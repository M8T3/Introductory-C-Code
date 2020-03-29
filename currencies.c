/* 
 * This program reads monetary values of different currencies and converts between them
 */
 
 #include <stdio.h>
 #include "simpio.h"
 #include "strlib.h"
 
 #define MaxStringLength 20
 
 typedef struct
 {
	string currencies[5];
	double values[5];
 } money;
 
 double MoneyCoversion(string old_money, string new_money, double amount_to_convert, money CurrencyExchange) 
 {
	int i = 0;
	double old_money_value;
	double new_money_value;
	while(StringCompare(CurrencyExchange.currencies[i], old_money) != 0)
	{	
		i++;
	}
	//printf("Old money to dollar rate: %g\n", CurrencyExchange.values[i]);
	old_money_value = amount_to_convert * CurrencyExchange.values[i];
	//printf("Old money value: %g\n", old_money_value);
	i = 0;
	while(StringCompare(CurrencyExchange.currencies[i], new_money) != 0)
	{
		i++;
	}
	//printf("New money to dollar rate: %g\n", CurrencyExchange.values[i]);
	new_money_value = old_money_value / CurrencyExchange.values[i];
	//printf("New money value: %g\n", new_money_value);
	return new_money_value;
 }
 
 money getExchangeRates(char *str, int n, FILE *stream, money DollarBills)
 {
	int i = 0;
	int num_of_lines = 0;
	string value_buffer;
	money MoneyExchange; 
	MoneyExchange = DollarBills;
	while(fgets(str, n, stream) != NULL)
	{ 
		if (num_of_lines > 5) break;
		int start = 0;
		int cpos = 0;
		while(IthChar(str, cpos) != ' ')
		{
			cpos++;
		}
		MoneyExchange.currencies[num_of_lines] = SubString(str, start, cpos-1);
		//printf("%s\n", MoneyExchange.currencies[num_of_lines]);
		while(IthChar(str, cpos) == ' ')
		{
			cpos++;
			start = cpos;
		}
		while(IthChar(str, cpos) != '\n')
		{
			cpos++;
		}
		value_buffer = SubString(str, start, cpos-1);
		MoneyExchange.values[num_of_lines] = StringToReal(value_buffer);
		//printf("%g\n", MoneyExchange.values[num_of_lines]);
		num_of_lines++;
	}
	return MoneyExchange;
 }
 
 void main()
 {
	money exchange_cash;
	string money_to_convert;
	string desired_money;
	double amount_of_money;
	double converted_amount_of_money;
	//double temp1;
	//double temp2;
	char buffer[MaxStringLength];
	FILE *infile;
	infile = fopen("exchange.dat", "r");	
	if(infile == NULL)
	{
		Error("Cannot open file");
	}
	exchange_cash = getExchangeRates(buffer, MaxStringLength, infile, exchange_cash);
	/*if(StringCompare(exchange_cash.currencies[0],"dollar") == 0)
	{
		printf("%s\n", "true");
	}
	else
	{
		printf("%s\n", "false");
	}*/
	printf("Convert from: ");
	money_to_convert = GetLine();
	printf("Convert into: ");
	desired_money = GetLine();
	printf("How many units of type %s? ", money_to_convert);
	amount_of_money = GetReal();
	converted_amount_of_money = MoneyCoversion(money_to_convert, desired_money, amount_of_money, exchange_cash);
	printf("%g %s = %g %s\n", amount_of_money, money_to_convert, converted_amount_of_money, desired_money);

	fclose(infile);
 }/*End of main()*/

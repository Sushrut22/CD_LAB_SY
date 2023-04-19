%{
	int vowel=0;
	int consonant =0;
    int line=0;
%}

%%
[aeiouAEIOU] {vowel++;}
[a-zA-Z] {consonant++;}
[\n] {line++;}
%%
int yywrap(){}
int main()
{
	printf("Enter the string ");
	yylex();
	printf("Number of vowels are: %d\n", vowel);
	printf("Number of consonants are: %d\n", consonant);
	printf("Number of lines are: %d\n", line);
	return 0;
}
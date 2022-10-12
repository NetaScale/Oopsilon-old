%{
#include <assert.h>
#include <string.h>

#include "driver.hh"
#include "parser.tab.hh"

#define YYDEBUG 1
%}

%code provides {
#include "driver.hh"

#define YY_DECL int true_stlex(STSTYPE *yylval, STLTYPE *loc, \
    yyscan_t yyscanner, ParserDriver * driver)

YY_DECL;
int stlex(STSTYPE *yylval, STLTYPE *loc, ParserDriver * driver);
}

%code requires {
#include "driver.hh"

void sterror(STLTYPE * loc, ParserDriver * driver, const char * msg);
void print_highlight(const char * txt, int first_line, int first_col,
    int last_line, int last_col);
}

%define api.pure
%define api.prefix {st}
%define parse.trace
%define parse.error verbose
%param { ParserDriver *driver }
%locations

%start Script

%token EOS

%%

Script: EOS;

%%

void sterror(STLTYPE * loc, ParserDriver * driver, const char * msg)
{
	printf("%d:%d: %s\n", loc->first_line + 1, loc->first_column,
	    msg);
	print_highlight(driver->txt, loc->first_line, loc->first_column,
	    loc->last_line, loc->last_column);
}

void print_highlight(const char * txt, int first_line, int first_col, int last_line, int last_col)
{
	int i;
	char fmt[9] = "";
	const char* lineend = txt;

	/* advance to the relevant line number */
	for (i = first_line ; i > 0; i--) {
		/* advance to next line */
		txt = strchr(txt, '\n');
		kassert(txt != NULL);
		txt++;
		kassert(*txt != '\0');
	}

	/* limit printing to not include line-terminal \n if present */
	lineend = strchr(txt, '\n');
	if (lineend != NULL)
		sprintf(fmt, "%%.%lds\n", lineend - txt);
	else
		sprintf(fmt, "%%s\n");

	printf(fmt, txt);
	for (i = 0; i < first_col; i++)
		putchar(' ');
	while(i++ < last_col)
		putchar('^');

	printf("\n");
}

int
stlex(STSTYPE *yylval, STLTYPE *loc, ParserDriver * driver)
{
	return true_stlex(yylval, loc, driver->scanner, driver);
}

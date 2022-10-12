#ifndef DRIVER_H_
#define DRIVER_H_

#ifndef YY_TYPEDEF_YY_SCANNER_T
#define YY_TYPEDEF_YY_SCANNER_T
typedef void* yyscan_t;
#endif

class STLTYPE;

class ParserDriver {
	int m_line = 0, m_col = 0, m_pos = 0;
	int m_oldLine = 0, m_oldCol = 0, m_oldPos = 0;

public:
	yyscan_t scanner;
	const char *txt;

	void recOldPos()
	{
		m_oldPos = m_pos;
		m_oldLine = m_line;
		m_oldCol = m_col;
	}

	void cr()
	{
		m_pos += m_col + 1;
		m_line++;
		m_col = 0;
	}
	void incCol() { m_col++; }

};

#endif /* DRIVER_H_ */

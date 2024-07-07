

enum TokenKind {
	EOF,
	NUMBER,
	STRING,
	IDENTIFIER,

	OPEN_BRACKET,
	CLOSE_BRACKET,
	OPEN_CURLY,
	CLOSE_CURLY,
	OPEN_PAREN,
	CLOSE_PAREN,

	ASSIGNEMENT,
	EQUALS,
	NOT,
	NOT_EQUALS,

	LESS,
	LESS_EQUALS,
	GREATER,
	GREATER_EQUALS,

	OR,
	AND,

	PLUS,
	DASH,
	SLACH,
	STAR,
	PERCENT,
};

typedef struct		s_token
{
	enum TokenKind	kind;
	char			value
}					t_token;

char	*token_kind_str(enum TokenKind kind)
{
	if (kind == EOF)
		return ("eof");
	if (kind == NUMBER)
		return ("number");
	if (kind == STRING)
		return ("string");
	if (kind == IDENTIFIER)
		return ("identifier");
	if (kind == OPEN_BRACKET)
		return ("open_bracket");
	if (kind == CLOSE_BRACKET)
		return ("close_bracket");
	if (kind == OPEN_CURLY)
		return ("open_curly");
	if (kind == CLOSE_CURLY)
		return ("close_curly");
	if (kind == OPEN_PAREN)
		return ("open_paren");
	if (kind == CLOSE_PAREN)
		return ("close_paren");
	if (kind == ASSIGNEMENT)
		return ("assignement");
	if (kind == EQUALS)
		return ("equals");
	if (kind == NOT_EQUALS)
		return ("not_equals");
	if (kind == NOT)
		return ("not");
	if (kind == LESS)
		return ("less");
	if (kind == GREATER)
		return ("greater");
	if (kind == GREATER_EQUALS)
		return ("greater_equals");
	if (kind == OR)
		return ("or");
	if (kind == AND)
		return ("and");
	if (kind == PLUS)
		return ("plus");
	if (kind == DASH)
		return ("dash");
	if (kind == SLACH)
		return ("slach");
	if (kind == STAR)
		return ("star");
	if (kind == PERCENT)
		return ("percent");
	return ((char *)0);
}

void	debug(t_token *token)
{
	if (token->kind == IDENTIFIER || token->kind == NUMBER || token->kind == STRING)
		printf("%s (%s)\n", token_kind_str(token->kind), token->value);
	else
		printf("%s ()\n", token_kind_str(token->kind));
}

t_token 
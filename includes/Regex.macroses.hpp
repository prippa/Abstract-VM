#ifndef REGEX_MACROSES_HPP
# define REGEX_MACROSES_HPP

# define CM_POP "pop"
# define CM_DUMP "dump"
# define CM_ADD "add"
# define CM_SUB "sub"
# define CM_MUL "mul"
# define CM_DIV "div"
# define CM_MOD "mod"
# define CM_PRINT "print"
# define CM_EXIT "exit"

// Bonus
# define CM_MORE "more"
# define CM_LESS "less"
# define CM_MAX "max"
# define CM_MIN "min"
# define CM_DEBUG "debug"

# define CM_PUSH "push"
# define CM_ASSERT "assert"

# define TP_INT8 "int8"
# define TP_INT16 "int16"
# define TP_INT32 "int32"
# define TP_FLOAT "float"
# define TP_DOUBLE "double"

# define REGEX_CMD_INDEX 1
# define REGEX_TYPE_INDEX 2
# define REGEX_VALUE_INDEX 3
# define REGEX_SPACES_NOT_ALWAYS "[\\s]*"
# define REGEX_SPACES_ALWAYS "[\\s]+"
# define REGEX_COMMENT_ALWAYS ";.*"
# define REGEX_COMMENT_NOT_ALWAYS "(;.*|[]{0,0})"
# define REGEX_NUM "[(](([-]?|[+]?)([\\d]+|[\\d]+.[\\d]+))[)]"

# define REGEX_CMD REGEX_SPACES_NOT_ALWAYS\
	"(" CM_POP "|" CM_DUMP "|" CM_ADD "|" CM_SUB "|" CM_MUL "|" CM_DIV "|" CM_MOD\
	"|" CM_PRINT "|" CM_EXIT "|" CM_MAX "|" CM_MIN "|" CM_DEBUG ")"\
	REGEX_SPACES_NOT_ALWAYS\
	REGEX_COMMENT_NOT_ALWAYS

# define REGEX_CMD_WITH_VALUE REGEX_SPACES_NOT_ALWAYS\
	"(" CM_PUSH "|" CM_ASSERT "|" CM_MORE "|" CM_LESS ")"\
	REGEX_SPACES_ALWAYS\
	"(" TP_INT8 "|" TP_INT16 "|" TP_INT32 "|" TP_FLOAT "|" TP_DOUBLE ")"\
	REGEX_NUM\
	REGEX_SPACES_NOT_ALWAYS\
	REGEX_COMMENT_NOT_ALWAYS

#endif

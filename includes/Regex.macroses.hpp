#ifndef REGEX_MACROSES_HPP
# define REGEX_MACROSES_HPP

# define REGEX_CMD_INDEX 1
# define REGEX_SPACES_NOT_ALWAYS "[\\s]*"
# define REGEX_SPACES_ALWAYS "[\\s]+"
# define REGEX_COMMENT_ALWAYS ";.*"
# define REGEX_COMMENT_NOT_ALWAYS "(;.*|[]{0,0})"
# define REGEX_NUM "[(](([-]?|[+]?)([\\d]+|[\\d]+.[\\d]+))[)]"

# define REGEX_CMD REGEX_SPACES_NOT_ALWAYS\
	"(pop|dump|add|sub|mul|div|mod|print|exit)"\
	REGEX_SPACES_NOT_ALWAYS\
	REGEX_COMMENT_NOT_ALWAYS

# define REGEX_CMD_WITH_VALUE REGEX_SPACES_NOT_ALWAYS\
	"(push|assert)"\
	REGEX_SPACES_ALWAYS\
	"(int8|int16|int32|float|double)"\
	REGEX_NUM\
	REGEX_SPACES_NOT_ALWAYS\
	REGEX_COMMENT_NOT_ALWAYS

#endif

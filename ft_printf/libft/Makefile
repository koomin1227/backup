CC= cc
CFLAGS= -Wall -Wextra -Werror
NAME= libft.a
FILES = ft_isalpha\
    ft_memcmp\
	ft_strdup\
	ft_strnstr\
	ft_atoi\
	ft_isascii\
	ft_memcpy\
	ft_strlcat\
	ft_strrchr\
	ft_bzero\
	ft_isdigit\
	ft_memmove\
	ft_strlcpy\
	ft_tolower\
	ft_calloc\
	ft_isprint\
	ft_memset\
	ft_strlen\
	ft_toupper\
	ft_isalnum\
	ft_memchr\
	ft_strchr\
	ft_strncmp\
	ft_substr\
	ft_strjoin\
	ft_strtrim\
	ft_split\
	ft_itoa\
	ft_strmapi\
	ft_striteri\
	ft_putchar_fd\
	ft_putstr_fd\
	ft_putendl_fd\
	ft_putnbr_fd\

FILES_B = ft_lstnew_bonus\
	ft_lstadd_front_bonus\
	ft_lstsize_bonus\
	ft_lstlast_bonus\
	ft_lstadd_back_bonus\
	ft_lstdelone_bonus\
	ft_lstclear_bonus\
	ft_lstiter_bonus\
	ft_lstmap_bonus\

SRCS=$(addsuffix .c, $(FILES))
SRCS_B=$(addsuffix .c, $(FILES_B))
OBJS=$(addsuffix .o, $(FILES))
OBJS_B=$(addsuffix .o, $(FILES_B))

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(NAME): $(OBJS)
	ar rcs $@ $^

all: $(NAME)

clean:
	rm -f $(OBJS) $(OBJS_B)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJS_B) $(OBJS)
	ar rcs $(NAME) $(OBJS) $(OBJS_B)

.PHONY: all, clean, fclean, re, bonus
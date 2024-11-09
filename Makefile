# コンパイラとフラグ
CC = cc
CFLAGS = -Wall -Wextra -Werror $(INCLUDE)
#CFLAGS = $(INCLUDE)
# ライブラリ名
NAME = libftprintf.a

# ソースディレクトリ
SRC_DIR = ./src
LIBFT_DIR = ./libft

# ソースコードとオブジェクトファイル
SRCS = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(LIBFT_DIR)/*.c)
OBJS = $(SRCS:.c=.o)

# インクルードディレクトリ
INCLUDE = -I ./include -I $(LIBFT_DIR)

# 削除コマンド
RM = rm -f

# テスト実行ファイル
TEST = test_exec

# すべてのファイルをコンパイル
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# ルール定義
.PHONY : all clean fclean re test

# デフォルトルール
all: $(NAME)

# オブジェクトファイル削除
clean:
	$(RM) $(OBJS)

# ライブラリとオブジェクトファイル削除
fclean: clean
	$(RM) $(NAME)

# 再生成
re: fclean all

test: $(NAME) testmain.c
	$(CC) $(CFLAGS) testmain.c -o $(TEST) -L. -lftprintf
	./$(TEST)
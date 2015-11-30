SRC = math.c numbers.c main.c
OUT = prog

CFLAGS = -g -Wall
LDFLAGS =

OBJS = $(SRC:.c=.o)
COV_OBJS = $(SRC:.c=.gcno) $(SRC:.c=.gcda)

all: $(OUT)

$(OUT): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

cov: CFLAGS += -fprofile-arcs -ftest-coverage
cov: LDFLAGS += -lgcov
cov: clean all

clean:
	rm -f $(OUT) $(OBJS) $(COV_OBJS)


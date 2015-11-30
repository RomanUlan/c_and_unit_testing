SRC = math_mock.cpp numbers_test.cpp
OUT = numbers_test
RUN_CMD = ./run.sh

TEST_APP = ../exe/prog
TEST_OBJS = ../exe/numbers.o
STUB_SRC = ../exe/math.c
STUB_LIB = libstubs.so

CFLAGS =
CXXFLAGS = -I../exe
LDDFLAGS = -Wl,--no-as-needed -L. -lgcov -ldl -lstubs -lgtest -lgmock -lgmock_main -pthread

TEST_APP_DIR = $(dir $(TEST_APP))
STUB_OBJS = $(STUB_SRC:.c=.sto)
OBJS = $(SRC:.cpp=.cxxo)

COV = cov
COV_REPORT_DIR = cov_report
COV_REPORT_DIR_HTML = $(COV_REPORT_DIR)/html
COV_REPORT_FILE = $(COV_REPORT_DIR)/coverage.info

all: $(TEST_APP) $(OUT) $(COV)

$(TEST_APP):
	make -C $(TEST_APP_DIR) $(COV)

$(OUT): $(OBJS) $(STUB_LIB)
	$(CXX) $(TEST_OBJS) $(OBJS) -o $@ $(LDDFLAGS)

%.cxxo: %.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

$(STUB_LIB): $(STUB_OBJS)
	$(CC) $(STUB_OBJS) -shared -o $@

%.sto: %.c
	$(CC) $(CFLAGS) -fPIC -c $^ -o $@

$(COV): run report

run:
	$(RUN_CMD)

report:
	mkdir -p $(COV_REPORT_DIR)
	lcov --capture --directory $(TEST_APP_DIR) --output-file $(COV_REPORT_FILE)
	genhtml $(COV_REPORT_FILE) --output-directory $(COV_REPORT_DIR_HTML)

clean_all: clean clean_test_app

clean:
	rm -rf $(COV_REPORT_DIR)
	rm -f $(OUT) $(OBJS) $(STUB_OBJS) $(STUB_LIB)

clean_test_app:
	make -C $(TEST_APP_DIR) clean


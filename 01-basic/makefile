# -n用于调试make脚本, 检查make是否有语法错误, 并不执行makefile
# make -f basic.make -n 
#
clean_files := *.o

.PHONY: default
default: hello


.PHONY: run
#### makefile术语
# 以下成为一个rule(target, prerequisites, commands)
# target: prerequisite [prerequisite ...]
#     command
#     .....
# 在command前加@表示不显示命令行
# 若command由shell执行(若不含shell关键词, 则该command可由make直接解释)
run:
	@echo "do foo.."
	@echo "do bar..."
	@./hello

clean_files += hello
hello: hello.o
	$(CC) -o $@ $^ $(LD_FLAGS)

# make支持-l<libname>的写法, 首先-l<libname>会被解释为lib<libnamne>.a, 然后动在标准路径中搜索
hello.o: hello.c -lc
	$(CC) $(CFLAGS) -c $^ -o $@ 


# 依赖关系可以写成多行
clean_files += calculator
calculator: add.o
calculator: sub.o
calculator: calculator.o
	$(CC) -o $@ $^ $(LD_FLAGS)

add.o: add.c
	$(CC) $(CFLAGS) -o $@ -c $< 

sub.o: sub.c
	$(CC) $(CFLAGS) -o $@ -c $< 

# 仅仅建立依赖关系, 表示op.h更新后需要重新构建calculator.o
# 除了头文件之外, 其他类似的依赖关系也可以这样使用
calculator.o: op.h

calculator.o: calculator.c
	$(CC) $(CFLAGS) -o $@ -c $< 


# 
# abc: many_c_files/*.c

### empty targets


### vpath
CFLAGS +=-g -ftest-coverage --coverage
LD_FLAGS += -lgcov

vpath %.c many_c_files
# vpath的缺陷是 a.c对应的gcda路径在 xx/make/a.gcda, 期望是xxx/make/many_c_files/a.gcda
# globbing pattern在变量中是不解释的, 被当成普通的字符串
clean_files += many_c *.gcno *.gcda
many_c: a.o b.o c.o main.o
	$(CC) -o $@ $^ $(LD_FLAGS)

a.o b.o c.o main.o: %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


.PHONY: clean
clean:
	rm -f $(clean_files)
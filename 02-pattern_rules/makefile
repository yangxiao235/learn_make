#
#
#
clean_files := *.o a/*.o

main: main.o sub_a.o

# what is a patten rule?
# A patttern rule looks like the normal rules,
# except the stem of the file(the portion before the suffix)
# is represented by a % character. 
#
# the built-in rules are all instances of pattern rules.
# 
# then percent character in a pattern rule is roughly equivalent
# to * in a UNIX shell. The percent character can be placed anywhere
# within the pattern but can **occur only once**. e.g.
#    %,v
#    s%.o
#
%.o: %.c
	$(COMPILE.c) $(OUTPUT_OPTION) $<


#
CFLAGS += -g -ftest-coverage --coverage
LD_FLAGS += -lgcov
clean_files += a/main a/.objs
A_MAIN := a/main
_A_OBJS:=a.o b.o main.o
_A_SRCS:=a.c b.c main.c
A_PREFIX := a/.objs
A_OBJS := $(addprefix $(A_PREFIX)/, $(_A_OBJS))
A_SRCS := $(patsubst %.o,%.c, $(A_OBJS))

.PHONY: create_obj_dir
$(A_MAIN): $(A_PREFIX) $(A_OBJS)
	$(CC) -o $@ $(A_OBJS) $(LD_FLAGS)

$(A_PREFIX):
	mkdir -p $@

$(A_OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(A_SRCS): $(A_PREFIX)/%.c: a/%.c
	cp -pf $< $@
	

clean:
	rm -rf $(clean_files)
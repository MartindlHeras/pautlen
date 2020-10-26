########################################################
# Makefile General que invoca a los otros 2 Makefiles
########################################################
all: make_src make_tests


make_src:
	cd src && $(MAKE)

make_tests:
	cd tests && $(MAKE)

.PHONY: clean_src clean_tests clean
clean_src:
	cd src && $(MAKE) clean

clean_tests:
	cd tests && $(MAKE) clean

clean: clean_src clean_tests
	rm -rf

########################################################
# Makefile General que invoca a los otros 2 Makefiles
########################################################

make_src:
	cd src && $(MAKE)

make_tests: makesrc
	cd test && $(MAKE)

.PHONY: cleansrc cleantests clean
cleansrc:
	cd src && $(MAKE) clean

cleantests:
	cd test && $(MAKE) clean

clean: cleansrc cleantests
	rm -rf *.o
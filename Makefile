all : 
	mkdir -p bin
	$(MAKE) -C bark
	$(MAKE) -C barkapp
	$(MAKE) -C blades

install :
	$(MAKE) -C bark install

uninstall :
	$(MAKE) -C bark uninstall

clean :
	$(MAKE) -C blades clean
	$(MAKE) -C barkapp clean
	$(MAKE) -C bark clean

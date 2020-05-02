PREFIX ?= /usr/local
LV2_URI_PREFIX = http://jpcima.sdf1.org/lv2

PLUGINS := fverb.lv2

all: $(PLUGINS)

clean:
	rm -rf $(PLUGINS)

install: all
	install -d $(DESTDIR)$(PREFIX)/lib/lv2
	$(foreach g,$(PLUGINS),cp -rfd $(g) $(DESTDIR)$(PREFIX)/lib/lv2;)

%.lv2: %.dsp
	faust2lv2 -uri-prefix $(LV2_URI_PREFIX) $<
	cp -f lv2-manifests/$@/*.ttl $@/
# epp:rangeSteps causes problems in some Ardour hosts
	sed -i '/epp:rangeSteps/d' $@/$*.ttl
# fix an error of faust LV2 generator
	sed -i 's/lv2:hardRtCapable/lv2:hardRTCapable/' $@/$*.ttl
# delete some fields manually overriden
	sed -i '/doap:license/d' $@/$*.ttl
	sed -i '/doap:maintainer/d' $@/$*.ttl

.PHONY: all clean install

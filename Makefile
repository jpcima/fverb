PREFIX ?= /usr/local
LV2_URI_PREFIX = http://jpcima.sdf1.org/lv2

PLUGINS := fverb.lv2

all: $(PLUGINS)
#	# set the plugin categories
	sed -i 's/a lv2:Plugin ;/a lv2:Plugin, lv2:ReverbPlugin ;/' fverb.lv2/manifest.ttl
#	# epp:rangeSteps causes problems in some Ardour hosts
	sed -i '/epp:rangeSteps/d' *.lv2/*.ttl
#	# fix an error of faust LV2 generator
	sed -i 's/lv2:optionalFeature lv2:hardRtCapable ;/lv2:optionalFeature lv2:hardRTCapable ;/' *.lv2/*.ttl

clean:
	rm -rf $(PLUGINS)

install: all
	install -d $(DESTDIR)$(PREFIX)/lib/lv2
	$(foreach g,$(PLUGINS),cp -rfd $(g) $(DESTDIR)$(PREFIX)/lib/lv2;)

%.lv2: %.dsp
	faust2lv2 -uri-prefix $(LV2_URI_PREFIX) $<

.PHONY: all clean install

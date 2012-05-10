#!/bin/bash
rake clean && rake && gem uninstall chromaprint && rake gem && gem install pkg/chromaprint-0.0.1.gem
#&& cp -r lib/chromaprint /Users/dceballos/.rvm/gems/ruby-1.9.2-p290/gems/chromaprint-0.0.1/lib/chromaprint

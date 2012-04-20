# -*- ruby -*-

require 'rubygems'
require 'hoe'
require 'rake/extensiontask'

# Hoe.plugin :compiler
# Hoe.plugin :gem_prelude_sucks
# Hoe.plugin :inline
# Hoe.plugin :racc
# Hoe.plugin :rcov
# Hoe.plugin :rubyforge

Hoe.spec 'chromaprint' do
  developer('Daniel Ceballos', 'daniel@cactus.fm')
  self.readme_file = 'README.rdoc'
  self.history_file = 'HISTORY.rdoc'
  self.extra_rdoc_files = FileList['*.rdoc']
  self.extra_dev_deps << ['rake-compiler', '>=0']
  self.spec_extras = {:extensions => ["ext/chromaprint/extconf.rb"]}

  Rake::ExtensionTask.new('chromaprint', spec) do |ext|
    ext.lib_dir = File.join('lib', 'chromaprint')
  end
end

Rake::Task[:test].prerequisites << :compile

# vim: syntax=ruby

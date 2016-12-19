# C

Memo files for programming in C

C言語を勉強するためのメモ

/extention の中には、Cで書いたRubyの拡張があります<br/>
<a href="">この記事</a>を読んで結構分かりやすかった<br/>

テストするには次のをする：
```
$ cd extension
$ ruby extconf.rb && make && make install
$ irb
irb> require 'foo'
=> true
irb> foo = Foo.new
=> <#Foo:0x007fe16a954bd0>
irb>foo.bar(1, 2.2, 'foobar')
[foobar * 1 + 2.200000 = 3.200000]
=> 3.2
```

という感じです。<br/>
本来は`ext`のディレクトリを作ってそこに入れるけど。<br/>


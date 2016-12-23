# C

Memo files for programming in C

C言語を勉強するためのメモ

/extention の中には、Cで書いたRubyの拡張があります<br/>
<a href="http://ser1zw.hatenablog.com/entry/20111217/1324133118" target="_blank" >この記事</a>を読んで結構分かりやすかった<br/>

次のコマンドで試してみることができます：
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


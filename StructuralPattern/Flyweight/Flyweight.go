package main

import (
	"fmt"
)

type User struct {
	Name string
}
type WebSite interface {
	Use(User)
}
type ConcrateWebSite struct {
	name string
}

func (c *ConcrateWebSite) Use(u User) {
	fmt.Println("网站分类：", c.name, " 用户：", u.Name)
}

type WebSiteFactory struct {
	m map[string]WebSite
}

func (w *WebSiteFactory) getWebSite(key string) WebSite {
	if _, ok := w.m[key]; !ok {
		w.m[key] = &ConcrateWebSite{
			name: key,
		}
	}
	return w.m[key]
}
func (w *WebSiteFactory) getCount() int {
	return len(w.m)
}

func main() {
	u1 := User{
		Name: "yy",
	}
	u2 := User{
		Name: "lcx",
	}
	f := WebSiteFactory{
		m: make(map[string]WebSite, 10),
	}
	w1 := f.getWebSite("产品展示")
	w1.Use(u1)
	w2 := f.getWebSite("产品展示")
	w2.Use(u2)
	w3 := f.getWebSite("博客")
	w3.Use(u1)
	w4 := f.getWebSite("博客")
	w4.Use(u2)
	fmt.Println("网站分类总数：", f.getCount())
}

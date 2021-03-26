package main

import "fmt"

type Request struct {
	name        string //消息来源
	requestType string // 消息类型，如请假
	count       int    // 数量，如请假天数
}
type Manager interface {
	requestApplication(Request)
}
type CommManager struct {
	Name  string
	Super *Manager
}

func (c *CommManager) requestApplication(r Request) {
	if r.requestType == "请假" && r.count <= 2 {
		fmt.Println(r.name, r.requestType, r.count)
	} else {
		(*c.Super).requestApplication(r)
	}
}

type Majordomo struct {
	Name  string
	Super *Manager
}

func (c *Majordomo) requestApplication(r Request) {
	if r.requestType == "请假" && r.count <= 5 {
		fmt.Println(r.name, r.requestType, r.count)
	} else {
		(*c.Super).requestApplication(r)
	}
}

// 还需要一个管理者，用于处理所有请求
func main() {
	var m2 Manager = &Majordomo{
		Name: "yy",
	}
	m1 := &Majordomo{
		Name:  "lcx",
		Super: &m2,
	}
	r1 := Request{
		name:        "hh",
		requestType: "请假",
		count:       2,
	}
	r2 := Request{
		name:        "xx",
		requestType: "请假",
		count:       5,
	}
	m1.requestApplication(r1)
	m1.requestApplication(r2)
}

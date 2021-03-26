package main

import "fmt"

type TeacherListenner interface {
	DoBadThing()
	StopBadThing()
	OnTeacherComming()
}
type Student struct {
	name     string
	badThing string
}

func (s *Student) DoBadThing() {
	fmt.Println(s.name, "在做", s.badThing)
}
func (s *Student) StopBadThing() {
	fmt.Println("老师来了", s.name, "停止做", s.badThing)
}
func (s *Student) OnTeacherComming() {
	s.StopBadThing()
}

type Monitor struct {
	students []TeacherListenner
}

func (m *Monitor) addListenner(s TeacherListenner) {
	m.students = append(m.students, s)
}
func (m *Monitor) removeListenner(s TeacherListenner) {
}
func (m *Monitor) notify() {
	for _, v := range m.students {
		v.OnTeacherComming()
	}
}
func main() {
	var m Monitor
	stu1 := &Student{
		name:     "lcx",
		badThing: "抄作业",
	}
	stu2 := &Student{
		name:     "yy",
		badThing: "玩手机",
	}
	m.addListenner(stu1)
	m.addListenner(stu2)
	m.notify()
}

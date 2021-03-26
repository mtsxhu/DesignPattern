package main

import "fmt"

type System01 struct {
}

func (s *System01) Run() {
	fmt.Println("sys 1 run")
}

type System02 struct {
}

func (s *System02) Run() {
	fmt.Println("sys 2 run")
}

type System03 struct {
}

func (s *System03) Run() {
	fmt.Println("sys 3 run")
}

type System04 struct {
}

func (s *System04) Run() {
	fmt.Println("sys 4 run")
}

type Facade struct {
	s01 System01
	s02 System02
	s03 System03
	s04 System04
}

func (f *Facade) RunA() {
	fmt.Println("Group A is running")
	f.s01.Run()
	f.s02.Run()
}

func (f *Facade) RunB() {
	fmt.Println("Group B is running")
	f.s03.Run()
	f.s04.Run()
}
func main() {
	f := Facade{
		s01: System01{},
		s02: System02{},
		s03: System03{},
		s04: System04{},
	}
	f.RunA()
	f.RunB()
}

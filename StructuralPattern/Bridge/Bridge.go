package main

type OS interface {
	Run()
}
type Phone interface {
	SetOS(*OS)
	Run()
}

type IPhone struct {
	os *OS
}

func (s *IPhone) SetSoft(os *OS) {
	s.os = os
}
func (s *IPhone) Run() {
	(*(s.os)).Run()
}

type Nokia struct {
	os *OS
}

func (s *Nokia) SetSoft(os *OS) {
	s.os = os
}
func (s *Nokia) Run() {
	(*(s.os)).Run()
}
func main() {

}

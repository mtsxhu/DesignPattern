package main

import "fmt"

type Phone interface {
	Show()
}
type IPhone struct {
}

func (*IPhone) Show() {
	fmt.Println("秀出IPhone")
}

type DecoratorPhone interface {
	Show()
}
type MoPhone struct {
	P Phone
}

func (*MoPhone) addMo() {
	fmt.Println("贴膜")
}
func (m *MoPhone) Show() {
	m.addMo()
	m.P.Show()
}

type TaoPhone struct {
	P Phone
}

func (*TaoPhone) addTao() {
	fmt.Println("装壳")
}
func (m *TaoPhone) Show() {
	m.addTao()
	m.P.Show()
}

func main() {
	var iPhone IPhone
	iPhone.Show()
	m := MoPhone{
		P: &iPhone,
	}
	m.Show()

	t := TaoPhone{
		P: &iPhone,
	}
	t.Show()

	mt := MoPhone{
		P: &t,
	}
	mt.Show()
}

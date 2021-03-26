package main

import "fmt"

type V5 interface {
	UseV5()
}
type ChargerAdapter struct {
	v220 V220
}

func (c *ChargerAdapter) UseV5() {
	fmt.Println("使用充电器对电压进行适配")
	c.v220.UseV220()
}

type V220 struct {
}

func (v *V220) UseV220() {
	fmt.Println("220V电压")
}

type Phone struct {
	c ChargerAdapter
}

func (p *Phone) Charge() {
	p.c.UseV5()
}
func main() {
	var p Phone
	p.Charge()
}

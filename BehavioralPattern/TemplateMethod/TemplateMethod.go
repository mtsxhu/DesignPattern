package main

import "fmt"

type IBeverage interface {
	// 煮⽔
	BoilWater()
	//	冲泡
	Brew()
	// 倒⼊杯中
	PourInCup()
	//	添加料 特殊接⼝
	AddCondiments()
}
type Beverage struct {
}

func (b *Beverage) BoilWater() {
	fmt.Println("煮水")
}
func (b *Beverage) Brew() {

}
func (b *Beverage) PourInCup() {
	fmt.Println("倒入杯中")
}

//	添加料 特殊接⼝,留给子类实现
func (b *Beverage) AddCondiments() {

}
func PrepareBeverage(i IBeverage) {
	i.BoilWater()
	i.AddCondiments()
	i.Brew()
	i.PourInCup()
}

type Coffee struct {
	*Beverage
}

func (b *Coffee) Brew() {
	fmt.Println("冲泡咖啡")
}
func (c *Coffee) AddCondiments() {
	fmt.Println("加入咖啡")
}

type Tea struct {
	*Beverage
}

func (b *Tea) Brew() {
	fmt.Println("冲泡茶叶")
}
func (c *Tea) AddCondiments() {
	fmt.Println("加入茶叶")
}

func main() {
	var b Beverage
	var i IBeverage = &Coffee{
		Beverage: &b,
	}
	PrepareBeverage(i)
	var i2 IBeverage = &Tea{
		Beverage: &b,
	}
	PrepareBeverage(i2)
}

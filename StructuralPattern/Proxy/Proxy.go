package main

import "fmt"

type GiveGift interface {
	GiveDolls()
	GiveFlowers()
	GiveChocolate()
}
type Pursuit struct {
	girlName string
}

func (p *Pursuit) GiveDolls() {
	fmt.Println("给", p.girlName, "洋娃娃")
}
func (p *Pursuit) GiveFlowers() {
	fmt.Println("给", p.girlName, "花")
}
func (p *Pursuit) GiveChocolate() {
	fmt.Println("给", p.girlName, "巧克力")
}

type Proxy struct {
	pu Pursuit
}

func (p *Proxy) GiveDolls() {
	fmt.Printf("帮别人")
	p.pu.GiveDolls()
}
func (p *Proxy) GiveFlowers() {
	fmt.Printf("帮别人")
	p.pu.GiveFlowers()
}
func (p *Proxy) GiveChocolate() {
	fmt.Printf("帮别人")
	p.pu.GiveChocolate()
}

func main() {
	pu := Pursuit{
		girlName: "lcx",
	}
	p := Proxy{
		pu: pu,
	}
	p.GiveDolls()
	p.GiveFlowers()
	p.GiveChocolate()
}

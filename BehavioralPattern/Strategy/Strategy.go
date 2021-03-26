package main

import "fmt"

type WeaponStrategy interface {
	UseWeapon()
}
type AK47 struct {
}

func (a *AK47) UseWeapon() {
	fmt.Println("use AK47")
}

type UZI struct {
}

func (a *UZI) UseWeapon() {
	fmt.Println("use UZI")
}

type Character struct {
	w WeaponStrategy
}

func (c *Character) SetWeapon(w WeaponStrategy) {
	c.w = w
}

func (c *Character) Attach() {
	fmt.Println("attach by:")
	c.w.UseWeapon()
}

func main() {
	var c Character
	var w1 WeaponStrategy = &AK47{}
	c.SetWeapon(w1)
	c.Attach()
	var w2 WeaponStrategy = &UZI{}
	c.SetWeapon(w2)
	c.Attach()
}

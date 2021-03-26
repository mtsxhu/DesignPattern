package main

import "fmt"

type Component interface {
	Add(Component)
	Remove(Component)
	DisPlay()
}
type Leaf struct {
	Name string
}

func (s *Leaf) Add(Component) {
	fmt.Println("leaf can not add")
}
func (s *Leaf) Remove(Component) {
	fmt.Println("leaf can not remove")
}
func (s *Leaf) DisPlay() {
	fmt.Println(s.Name)
}

type Composite struct {
	Name     string
	ComSlice []Component
}

func (c *Composite) Add(co Component) {
	b := true
	for _, v := range c.ComSlice {
		if v == co {
			b = false
		}
	}
	if b {
		c.ComSlice = append(c.ComSlice, co)
	}
}
func (c *Composite) Remove(co Component) {
	for i, v := range c.ComSlice {
		if v == co {
			c.ComSlice = append(c.ComSlice[:i-1], c.ComSlice[i+1:]...)
		}
	}
}
func (c *Composite) DisPlay() {
	for _, v := range c.ComSlice {
		v.DisPlay()
	}
}
func main() {
	p := Composite{Name: "总部"}
	p.Add(&Leaf{Name: "总部财务部门"})
	p.Add(&Leaf{Name: "总部人力资源部门"})

	p1 := Composite{Name: "上海分部"}
	p1.Add(&Leaf{Name: "上海分部财务部门"})
	p1.Add(&Leaf{Name: "上海分部人力资源部门"})

	p.Add(&p1)
	p.DisPlay()
}

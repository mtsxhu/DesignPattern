package main

import "fmt"

type Babecuer struct {
	Name string
}

func (b *Babecuer) BakeMutton() {
	fmt.Println("烤羊肉串")
}
func (b *Babecuer) BakeChicken() {
	fmt.Println("烤鸡腿")
}

type Command interface {
	excuteCommand()
}
type BakeMuttonCommand struct {
	Babecuer
}

func (b *BakeMuttonCommand) excuteCommand() {
	b.Babecuer.BakeMutton()
}

type BakeChickenCommand struct {
	Babecuer
}

func (b *BakeChickenCommand) excuteCommand() {
	b.Babecuer.BakeChicken()
}

type Waiter struct {
	coms []Command
}

func (w *Waiter) setOrder(c Command) {
	switch c.(type) {
	case *BakeChickenCommand:
		fmt.Println("鸡腿没了")
	case *BakeMuttonCommand:
		fmt.Println("创建羊肉串订单")
		w.coms = append(w.coms, c)
	}
}
func (w *Waiter) notify() {
	for _, v := range w.coms {
		v.excuteCommand()
	}
}
func main() {
	w := &Waiter{
		coms: make([]Command, 0, 10),
	}
	var r Babecuer
	c1 := &BakeMuttonCommand{
		Babecuer: r,
	}
	c2 := &BakeMuttonCommand{
		Babecuer: r,
	}
	c3 := &BakeChickenCommand{
		Babecuer: r,
	}
	w.setOrder(c1)
	w.setOrder(c2)
	w.setOrder(c3)

	w.notify()
}

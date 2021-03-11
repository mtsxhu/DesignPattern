package main

import "fmt"

type PersonBuilder interface {
	BuildHead()
	BuildBody()
	BuildArmLeft()
	BuildArmRight()
	BuildLegLeft()
	BuildLegRight()
}
type PersonThinBuilder struct {
}

func (this *PersonThinBuilder) BuildHead() {
	fmt.Println("build thin person head")
}
func (this *PersonThinBuilder) BuildBody() {
	fmt.Println("build thin person body")
}
func (this *PersonThinBuilder) BuildArmLeft() {
	fmt.Println("build thin person left arm")
}
func (this *PersonThinBuilder) BuildArmRight() {
	fmt.Println("build thin person right arm")
}
func (this *PersonThinBuilder) BuildLegLeft() {
	fmt.Println("build thin person left leg")
}
func (this *PersonThinBuilder) BuildLegRight() {
	fmt.Println("build thin person right leg")
}

type PersonfatBuilder struct {
}

func (this *PersonfatBuilder) BuildHead() {
	fmt.Println("build fat person head")
}
func (this *PersonfatBuilder) BuildBody() {
	fmt.Println("build fat person body")
}
func (this *PersonfatBuilder) BuildArmLeft() {
	fmt.Println("build fat person left arm")
}
func (this *PersonfatBuilder) BuildArmRight() {
	fmt.Println("build fat person right arm")
}
func (this *PersonfatBuilder) BuildLegLeft() {
	fmt.Println("build fat person left leg")
}
func (this *PersonfatBuilder) BuildLegRight() {
	fmt.Println("build fat person right leg")
}

type PersonDirector struct {
}

func (this *PersonDirector) BuildPerson(p PersonBuilder) {
	p.BuildHead()
	p.BuildBody()
	p.BuildArmLeft()
	p.BuildArmRight()
	p.BuildLegLeft()
	p.BuildLegRight()
}
func main() {
	var pt PersonThinBuilder
	var pf PersonfatBuilder
	var pd PersonDirector
	pd.BuildPerson(&pt)
	pd.BuildPerson(&pf)
}

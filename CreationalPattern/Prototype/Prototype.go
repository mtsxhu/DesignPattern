package main

import "fmt"

type Resumer interface {
	ShallowClone() Resumer
	DeepClone() Resumer
}

type Resume struct {
	Name string
	Age  int
}

func (this Resume) DeepClone() Resumer {
	return &this
}
func (this *Resume) ShallowClone() Resumer {
	return this
}

func main() {
	fmt.Println("===========>	深拷贝")
	resume := &Resume{"lcx", 12}
	resume2 := resume.DeepClone().(*Resume)
	fmt.Printf("resume：%+v\n", resume)
	fmt.Printf("resume2：%+v\n", resume2)
	resume2.Name = "yy"
	fmt.Printf("resume：%+v\n", resume)
	fmt.Printf("resume2：%+v\n", resume2)
	fmt.Println("===========>	浅拷贝")
	resume3 := resume.ShallowClone().(*Resume)
	fmt.Printf("resume：%+v\n", resume)
	fmt.Printf("resume3：%+v\n", resume3)
	resume3.Name = "hhh"
	fmt.Printf("resume：%+v\n", resume)
	fmt.Printf("resume3：%+v\n", resume3)
}

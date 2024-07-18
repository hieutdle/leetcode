package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"path/filepath"
	"strings"
)

func main() {
	root := "./medium" // replace this with the root directory to search for .go files
	err := filepath.Walk(root, func(path string, info os.FileInfo, err error) error {
		if !info.IsDir() && strings.HasSuffix(info.Name(), ".go") {
			fileBytes, err := ioutil.ReadFile(path)
			if err != nil {
				return err
			}
			newContent := strings.Replace(string(fileBytes), "medium", "algorithms", -1)
			err = ioutil.WriteFile(path, []byte(newContent), 0)
			if err != nil {
				return err
			}
		}
		return nil
	})

	if err != nil {
		fmt.Println(err)
		return
	}
	fmt.Println("Successfully replaced package name in all .go files.")
}

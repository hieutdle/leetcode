package gods

type Stack struct {
	Items []interface{}
}

func (s *Stack) Push(item interface{}) {
	s.Items = append(s.Items, item)
}

func (s *Stack) Pop() interface{} {
	if len(s.Items) == 0 {
		return nil
	}

	l := len(s.Items) - 1

	toRemove := s.Items[l]

	// Remove the last item
	s.Items = s.Items[:l]

	return toRemove
}

func (s *Stack) Peek() interface{} {
	if len(s.Items) == 0 {
		return nil
	}

	return s.Items[len(s.Items)-1]
}

func (s *Stack) IsEmpty() bool {
	return len(s.Items) == 0
}

func (s *Stack) Size() int {
	return len(s.Items)
}

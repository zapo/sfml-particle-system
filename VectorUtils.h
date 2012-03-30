template <class T>
std::ostream & operator<<(std::ostream & stream, sf::Vector2<T> vec) {

	stream << "x : " << (int) vec.x;
	stream << " y : " << (int) vec.y;

	return stream;
}

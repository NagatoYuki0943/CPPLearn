cmake_minimum_required(VERSION 3.17)
project(05)

set(CMAKE_CXX_STANDARD 20)
include_directories(files/)

add_executable(05 main.cpp)
add_executable(02template_basic files/02template_basic.cpp)
add_executable(03template_attention files/03template_attention.cpp)
add_executable(04template_example files/04template_example.cpp)
add_executable(05function_template00 files/05function_template00.cpp)
add_executable(06function_template01 files/06function_template01.cpp)
add_executable(07template_limit files/07template_limit.cpp)
add_executable(08template_class files/08template_class.cpp)
add_executable(09template_function_class files/09template_function_class.cpp)
add_executable(10class_function_create_time files/10class_function_create_time.cpp)
add_executable(11class_function_argument files/11class_function_argument.cpp)
add_executable(12template_class_inherit files/12template_class_inherit.cpp)
add_executable(13class_function files/13class_function.cpp)
add_executable(14template_files files/14template_files.cpp )
add_executable(15template_class_friend files/15template_class_friend.cpp)
add_executable(16template_class_example files/16template_class_example.cpp)
add_executable(16template_class_example1 files/16template_class_example1.cpp)
add_executable(19STL_basic files/19STL_basic.cpp)
add_executable(20STL_vector01 files/20STL_vector01.cpp)
add_executable(21STL_vector02 files/21STL_vector02.cpp)
add_executable(22STL_vector_nesting files/22STL_vector_nesting.cpp)
add_executable(23string_basic files/23string_basic.cpp)
add_executable(24string_assign files/24string_assign.cpp)
add_executable(25string_append files/25string_append.cpp)
add_executable(26string_find_replace files/26string_find_replace.cpp)
add_executable(27string_compare files/27string_compare.cpp)
add_executable(28string_at files/28string_at.cpp)
add_executable(29string_insert_erase files/29string_insert_erase.cpp)
add_executable(30string_substr files/30string_substr.cpp)
add_executable(31vector_basic files/31vector_push_back_pop_back.cpp)
add_executable(32vector_assign files/32vector_assign.cpp)
add_executable(33vector_empty_capacity_size "files/33vector_empty_capacity_size_ resize.cpp")
add_executable(34vector_insert_erase_clear files/34vector_insert_erase_clear.cpp)
add_executable(35vector_at_front_back files/35vector_at_front_back.cpp)
add_executable(36vector_swap files/36vector_swap.cpp)
add_executable(37vector_reserve files/37vector_reserve.cpp)
add_executable(38deque_basic files/38deque_push_back_pop_back_push_front_pop_front.cpp)
add_executable(39deque_assign files/39deque_assign.cpp)
add_executable(40deque_empty_size files/40deque_empty_size_resize.cpp)
add_executable(41deque_insert_erase_clear files/41deque_insert_erase_clear.cpp)
add_executable(42deque_at_front_back files/42deque_at_front_back.cpp)
add_executable(43vector_deque_sort files/43algorithm_vector_deque_sort.cpp)
add_executable(44STL_example01 files/44STL_example01.cpp)
add_executable(45stack_basic files/45stack_basic.cpp)
add_executable(46stack_func files/46stack_push_pop_top_empty_size.cpp)
add_executable(47queue_basic files/47queue_basic.cpp)
add_executable(48queue_func files/48queue_push_pop_front_back_empty_size.cpp)
add_executable(49list_basic files/49list_basic.cpp)
add_executable(50list_construct files/50list_push_back_pop_back_push_front_pop_front.cpp)
add_executable(51list_assign_swap files/51list_assign_swap.cpp)
add_executable(52list_empty_size files/52list_empty_size_resize.cpp)
add_executable(53list_insert_erase_clear_remove files/53list_insert_erase_clear_remove.cpp)
add_executable(54list_front_back files/54list_front_back.cpp)
add_executable(55list_reverse_sort files/55list_reverse_sort.cpp)
add_executable(56list_sort_example files/56list_sort_example.cpp)
add_executable(57set_basic files/57set_basic.cpp)
add_executable(58set_empty_size_swap files/58set_empty_size_swap.cpp)
add_executable(59set_insert_erase_clear files/59set_insert_erase_clear.cpp)
add_executable(60set_find_count files/60set_find_count.cpp)
add_executable(61set_multiset_diff files/61set_multiset_diff.cpp)
add_executable(62pair files/62pair.cpp)
add_executable(63set_sort files/63set_sort.cpp)
add_executable(64set_sort_person files/64set_sort_person.cpp)
add_executable(65map_basic files/65map_basic.cpp)
add_executable(66map_empty_size_swap files/66map_empty_size_swap.cpp)
add_executable(67map_insert_erase_clear files/67map_insert_erase_clear.cpp)
add_executable(68map_find_count files/68map_find_count.cpp)
add_executable(69map_sort files/69map_sort.cpp)
add_executable(70STL_example02 files/70STL_example02.cpp)
add_executable(71function_object files/71function_object.cpp)
add_executable(73_binary_predicate files/73_binary_predicate.cpp)
add_executable(72_unary_predicate files/72_unary_predicate.cpp)
add_executable(74internal_function_object_calculate files/74plus_minus_pultiplies_divides_modules_negate.cpp)
add_executable(75internal_function_object_relation files/75greater_less_equal.cpp)
add_executable(76internal_function_object_logical files/76logical_transform.cpp)
add_executable(77traverse_for_each files/77for_each.cpp)
add_executable(78traverse_transform files/78transform.cpp)
add_executable(79find_find files/79find.cpp)
add_executable(80find_find_if files/80find_if.cpp)
add_executable(81find_adjacent_find files/81adjacent_find.cpp)
add_executable(82find_binary_search files/82binary_search.cpp)
add_executable(83find_count files/83count.cpp)
add_executable(84find_count_if files/84count_if.cpp)

add_executable(85sort_sort files/85sort.cpp)
add_executable(86sort_random_shuffle files/86random_shuffle.cpp)
add_executable(87sort_merge files/87merge.cpp)
add_executable(88sort_reverse files/88reverse.cpp)
add_executable(92swap files/92swap.cpp)
add_executable(91replace_if files/91replace_if.cpp)
add_executable(90replace files/90replace.cpp)
add_executable(89copy files/89copy.cpp)
add_executable(93numeric_accumulate files/93numeric_accumulate.cpp)
add_executable(94numeric_fill files/94numeric_fill.cpp)
add_executable(95set_intersection files/95set_intersection.cpp)
add_executable(96set_union files/96set_union.cpp)
add_executable(97set_difference files/97set_difference.cpp)
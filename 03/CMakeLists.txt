cmake_minimum_required(VERSION 3.17)
project(03)

include_directories(header)
set(CMAKE_CXX_STANDARD 20)

add_executable(03 main.cpp)
add_executable(01global files/01global.cpp)
add_executable(02quan_jv_qv files/02quan_jv_qv.cpp)
add_executable(03zhan_qv files/03zhan_qv.cpp)
add_executable(04dui_qv files/04dui_qv.cpp)
add_executable(06bie_ming files/06bie_ming.cpp)
add_executable(08yin_yong_zuo_han_shu_can_shu files/08yin_yong_zuo_han_shu_can_shu.cpp)
add_executable(09yin_yong_zuo_wei_han_shu_fan_hui_zhi files/09yin_yong_zuo_wei_han_shu_fan_hui_zhi.cpp)
add_executable(10yin_yong_essence files/10yin_yong_essence.cpp)
add_executable(11const_yin_yong files/11const_yin_yong.cpp)
add_executable(12han_shu_mo_ren_can_shu files/12han_shu_mo_ren_can_shu.cpp)
add_executable(13zhan_wei_can_shu files/13zhan_wei_can_shu.cpp)
add_executable(14han_shu_chong_zai files/14han_shu_chong_zai.cpp)
add_executable(15han_shu_chong_zai files/15han_shu_chong_zai.cpp)
add_executable(16class00 files/16class00.cpp)
add_executable(17class01 files/17class01.cpp)
add_executable(18feng_zhuang files/18feng_zhuang.cpp)
add_executable(19class_struct files/19class_struct.cpp)
add_executable(20private files/20private.cpp)
add_executable(21class_test00 files/21class_test00.cpp)
add_executable(22class_test01 files/22class_test01.cpp files/22class_test01.point.cpp files/22class_test01.circle.cpp)
add_executable(23class_construct00 files/23class_construct00.cpp)
add_executable(24class_construct01 files/24class_construct01.cpp)
add_executable(25class_construct02 files/25class_construct02.cpp)
add_executable(26class_construct03 files/26class_construct03.cpp)
add_executable(27class_construct04 files/27class_construct04.cpp)
add_executable(28class_start files/28class_start.cpp)
add_executable(29class_qian_tao files/29class_qian_tao.cpp)
add_executable(30class_static_member files/30class_static_member.cpp)
add_executable(31class_static_function files/31class_static_function.cpp)
add_executable(32object_property files/32object_property.cpp)
add_executable(33this_point files/33this_point.cpp)
add_executable(34empty_point files/34empty_point.cpp)
add_executable(35class_const_function "files/35class_const_function.cpp")
add_executable(36class_friend00 files/36class_friend00.cpp)
add_executable(37class_friend01 files/37class_friend01.cpp)
add_executable(38class_friend02 files/38class_friend02.cpp)
add_executable(39yun_suan_fu+ files/39yun_suan_fu+.cpp)
add_executable(40yun_suan_fu_left files/40yun_suan_fu_left.cpp)
add_executable(41yun_suan_fu++ files/41yun_suan_fu++.cpp)
add_executable(42yun_suan_fu_fu_zhi files/42yun_suan_fu_fu_zhi.cpp)
add_executable(43yun_suan_fu_guan_xi files/43yun_suan_fu_guan_xi.cpp)
add_executable(44yun_suan_fu_han_shu files/44yun_suan_fu_han_shu.cpp)
add_executable(45inherit_basic files/45inherit_basic.cpp)
add_executable(46_1inherit_ways files/46_1inherit_ways.cpp)
add_executable(46_2inherit_pramaters files/46_2inherit_pramaters.cpp)
add_executable(47inherit_object files/47inherit_object.cpp)
add_executable(48inherit_construct files/48inherit_construct.cpp)
add_executable(49inherit_same_name files/49inherit_same_name.cpp)
add_executable(50inherit_same_name_static files/50inherit_same_name_static.cpp)
add_executable(51multi_inherit files/51multi_inherit.cpp)
add_executable(52diamond_inherit files/52diamond_inherit.cpp)
add_executable(53duo_tai00 files/53duo_tai00.cpp)
add_executable(55duo_tai_test00 files/55duo_tai_test00.cpp)
add_executable(56virtual_abstract files/56virtual_abstract.cpp)
add_executable(57duo_tai_test01 files/57duo_tai_test01.cpp)
add_executable(58virtual_destruct files/58virtual_destruct.cpp)
add_executable(59duo_tai_test03 files/59duo_tai_test03.cpp)
add_executable(61file_write_out files/61file_write_out.cpp)
add_executable(62file_read_in files/62file_read_in.cpp)
add_executable(63file_binary_write_out files/63file_binary_write_out.cpp)
add_executable(64file_binary_read_in files/64file_binary_read_in.cpp)
add_executable(test test.cpp)

add_executable(30class_const files/30class_const.cpp)

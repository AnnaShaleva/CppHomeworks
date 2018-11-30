gtest = dependency('gtest', main: true)
test(
	'myclass',
	executable(
		'MyVector_test',
		include_directories: src,
		sources: ['MyVector_test.cpp',
			'Group_test.cpp',
			'MyArray_test.cpp',
			'Rotate_test.cpp',
			'Message_test.cpp',
			'MyGuard_test.cpp',
			'Trait_test.cpp',
			'MyArray_param_test.cpp',
			'MyVector_test.cpp',
			'User_test.cpp'],
		dependencies: [gtest]
	)
)


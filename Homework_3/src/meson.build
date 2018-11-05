gtest = dependency('gtest', main: true)
test(
	'myclass',
	executable(
		'Message_test',
		include_directories: include_directories('.'),
		sources: ['Message_test.cpp'],
		dependencies: [gtest]
	)
)


project(
	'myproject',
	'cpp',
	version: '0.1.0',
	meson_version: '>=0.4.5.1',
	default_options: ['cpp_std=c++11']
)
gtest = dependency('gtest', main: true)
test(
	'myclass',
	executable(
		'Guard_test',
		include_directories: include_directories('.'),
		sources: ['MyGuard_test.cpp'],
		dependencies: [gtest]
	)
)

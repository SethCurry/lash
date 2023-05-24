all:
	bazel build //lash:lash
t:
	bazel test --test_output=all //test/lang:lexer_test

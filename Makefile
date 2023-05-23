all:
	bazel build //lash:lash
t:
	bazel test --test_output=all //test:lash_test

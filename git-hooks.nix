{ pkgs, ... }:
{
  hooks = {
    action-validator.enable = true;
    actionlint.enable = true;
    check-merge-conflicts.enable = true;
    clang-format.enable = true;
    clang-tidy = {
      # TODO: make clang-tidy work again
      enable = false;
      entry = "${pkgs.llvmPackages_21.clang-tools}/bin/clang-tidy -p build";
    };
    commitizen.enable = true;
    deadnix.enable = true;
    end-of-file-fixer.enable = true;
    markdownlint.enable = true;
    nixfmt-rfc-style.enable = true;
    ruff-format.enable = true;
    ruff.enable = true;
    trim-trailing-whitespace.enable = true;
  };
}

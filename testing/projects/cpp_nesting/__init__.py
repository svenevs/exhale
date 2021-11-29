"""
The ``cpp_nesting`` test project.
"""

from testing.hierarchies import clike, directory, file, namespace, union


def default_class_hierarchy_dict():
    """Return the default class hierarchy dictionary."""
    return {
        clike("struct", "top_level"): {},
        namespace("nested"): {
            clike("struct", "one"): {
                clike("struct", "params"): {
                    union("four_bytes"): {}
                }
            },
            clike("struct", "two"): {
                clike("struct", "params"): {
                    union("four_bytes"): {}
                }
            },
            union("four_bytes"): {},
            namespace("dual_nested"): {
                clike("struct", "one"): {
                    clike("struct", "params"): {
                        union("four_bytes"): {}
                    }
                },
                clike("struct", "two"): {
                    clike("struct", "params"): {
                        union("four_bytes"): {}
                    }
                }
            }
        }
    }


def default_file_hierarchy_dict():
    """Return the default file hierarchy dictionary."""
    return {
        directory("include"): {
            file("top_level.hpp"): {
                clike("struct", "top_level"): {}
            },
            directory("nested"): {
                directory("one"): {
                    file("one.hpp"): {
                        namespace("nested"): {
                            clike("struct", "one"): {
                                clike("struct", "params"): {
                                    union("four_bytes"): {}
                                }
                            }
                        }
                    },
                },
                directory("two"): {
                    file("two.hpp"): {
                        namespace("nested"): {
                            clike("struct", "two"): {
                                clike("struct", "params"): {
                                    union("four_bytes"): {}
                                }
                            },
                            union("four_bytes"): {}
                        }
                    }
                },
                directory("dual_nested"): {
                    directory("one"): {
                        file("one.hpp"): {
                            namespace("nested"): {
                                namespace("dual_nested"): {
                                    clike("struct", "one"): {
                                        clike("struct", "params"): {
                                            union("four_bytes"): {}
                                        }
                                    }
                                }
                            }
                        }
                    },
                    directory("two"): {
                        file("two.hpp"): {
                            namespace("nested"): {
                                namespace("dual_nested"): {
                                    clike("struct", "two"): {
                                        clike("struct", "params"): {
                                            union("four_bytes"): {}
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

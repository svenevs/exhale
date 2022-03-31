"""
The ``cpp_nesting`` test project.
"""

from testing.hierarchies import clike, directory, file, namespace, union


def default_class_hierarchy_dict():
    """Return the default class hierarchy dictionary."""
    return {
        clike("struct", "top_level"): {},
        namespace("special"): {
            clike("struct", "Normal"): {
                clike("struct", "Nested"): {
                    clike("struct", "Like"): {
                        clike("struct", "Usual"): {}
                    }
                }
            },
            clike("struct", "Image", template=["int width", "int height"]): {},
            clike("class", "ImageBuffer", template=[
                "class TImage", "typename Tdata_t", "int Tchannels"]): {
                clike("struct", "Data"): {},
                clike("struct", "SomeThing", template=["int Tnested"]): {}
            },
            clike("class", "ImageBuffer", template=[
                "class TImage", "typename Tdata_t"]): {
                clike("struct", "Data"): {},
                clike("struct", "SomeThing"): {}
            },
            clike("class", "ImageBuffer"): {
                clike("struct", "Data"): {},
                clike("struct", "SomeThing"): {}
            },
            # TODO: undo #if 0 in nesting_specializations.hpp
            # clike("struct", "Base", template=["size_t N"]): {
            #     clike("struct", "A"): {}
            # },
            # clike("struct", "Base"): {
            #     clike("struct", "InnerStruct"): {},
            #     clike("struct", "AnotherNestedStruct"): {},
            #     clike("struct", "InnerTemplatedStruct", template=[
            #         "size_t M", "typename no_use_this = void"]): {},
            #     clike("struct", "InnerTempaltedStruct", template=[
            #         "typename dont_use_this"]): {}
            # }
        },
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
            file("nesting_specializations.hpp"): {
                namespace("special"): {
                    clike("struct", "Normal"): {
                        clike("struct", "Nested"): {
                            clike("struct", "Like"): {
                                clike("struct", "Usual"): {}
                            }
                        }
                    },
                    clike("struct", "Image", template=["int width", "int height"]): {},
                    clike("class", "ImageBuffer", template=[
                        "class TImage", "typename Tdata_t", "int Tchannels"]): {
                        clike("struct", "Data"): {},
                        clike("struct", "SomeThing", template=["int Tnested"]): {}
                    },
                    clike("class", "ImageBuffer", template=[
                        "class TImage", "typename Tdata_t"]): {
                        clike("struct", "Data"): {},
                        clike("struct", "SomeThing"): {}
                    },
                    clike("class", "ImageBuffer"): {
                        clike("struct", "Data"): {},
                        clike("struct", "SomeThing"): {}
                    },
                    # TODO: undo #if 0 in nesting_specializations.hpp
                    # clike("struct", "Base", template=["size_t N"]): {
                    #     clike("struct", "A"): {}
                    # },
                    # clike("struct", "Base"): {
                    #     clike("struct", "InnerStruct"): {},
                    #     clike("struct", "AnotherNestedStruct"): {},
                    #     clike("struct", "InnerTemplatedStruct", template=[
                    #         "size_t M", "typename no_use_this = void"]): {},
                    #     clike("struct", "InnerTempaltedStruct", template=[
                    #         "typename dont_use_this"]): {}
                    # }
                }
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

"""
The ``cpp_nesting`` test project.
"""

from testing.hierarchies import clike, directory, file, namespace, typedef, union


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
            clike("class", "ImageBuffer< TImage, Tdata_t, 4 >", template=[
                "class TImage", "typename Tdata_t"]): {
                clike("struct", "Data"): {},
                clike("struct", "SomeThing"): {}
            },
            clike("class", "ImageBuffer< Image< 1920, 1080 >, float, 128 >"): {
                clike("struct", "Data"): {},
                clike("struct", "SomeThing"): {}
            },
            clike("struct", "Base", template=["size_t N"]): {
                clike("struct", "A"): {}
            },
            clike("struct", "Base< 2 >", template=["2"]): {
                clike("struct", "InnerStruct"): {},
                clike("struct", "AnotherNestedStruct"): {},
                clike("struct", "InnerTemplatedStruct", template=[
                    "size_t M", "typename no_use_this = void"]): {},
                clike("struct", "InnerTemplatedStruct< 4, dont_use_this >", template=[
                    "typename dont_use_this"]): {}
            },
            namespace("unique"): {
                namespace("snowflake"): {
                    clike("struct", "Ontology", template=["auto Epoch"]): {},
                    clike("struct", "Ontology< 11 >", template=["11"]): {},
                },
                clike("struct", "Nonsense", template=["int X", "class T"]): {},
                clike("struct", "Nonsense< X, snowflake::Ontology< X > >",
                      template=["int X"]): {},
                clike("struct", "Nonsense< 11, snowflake::Ontology< 11 > >"): {},
                typedef("PartialNonsense", "Nonsense< X, snowflake::Ontology< X > >",
                        template=["int X"]): {},
                typedef("FullNonsense", "Nonsense< 11, snowflake::Ontology< 11 > >"): {}
            },
            namespace("complex"): {
                clike("struct", "Fold", template=["typename... Ts"]): {},
                typedef("void_t", "void", template=["class..."]): {},
                clike("struct", "has_type_member",
                      template=["class", "class=void"]): {},
                clike("struct", "has_type_member< T, void_t< typename T::type > >",
                      template=["class T"]): {},
                clike("struct", "IntPtr", template=["const int* I"]): {},
                clike("struct", "IntRef", template=["const int& I"]): {}
            }
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
                    clike("class", "ImageBuffer< TImage, Tdata_t, 4 >", template=[
                        "class TImage", "typename Tdata_t"]): {
                        clike("struct", "Data"): {},
                        clike("struct", "SomeThing"): {}
                    },
                    clike("class", "ImageBuffer< Image< 1920, 1080 >, float, 128 >"): {
                        clike("struct", "Data"): {},
                        clike("struct", "SomeThing"): {}
                    },
                    clike("struct", "Base", template=["size_t N"]): {
                        clike("struct", "A"): {}
                    },
                    clike("struct", "Base< 2 >", template=["2"]): {
                        clike("struct", "InnerStruct"): {},
                        clike("struct", "AnotherNestedStruct"): {},
                        clike("struct", "InnerTemplatedStruct", template=[
                            "size_t M", "typename no_use_this = void"]): {},
                        clike("struct", "InnerTemplatedStruct< 4, dont_use_this >", template=[
                            "typename dont_use_this"]): {}
                    },
                    namespace("unique"): {
                        namespace("snowflake"): {
                            clike("struct", "Ontology", template=["auto Epoch"]): {},
                            clike("struct", "Ontology< 11 >", template=["11"]): {},
                        },
                        clike("struct", "Nonsense", template=["int X", "class T"]): {},
                        clike("struct", "Nonsense< X, snowflake::Ontology< X > >",
                              template=["int X"]): {},
                        clike("struct", "Nonsense< 11, snowflake::Ontology< 11 > >"): {},
                        typedef("PartialNonsense",
                                "Nonsense< X, snowflake::Ontology< X > >",
                                template=["int X"]): {},
                        typedef("FullNonsense",
                                "Nonsense< 11, snowflake::Ontology< 11 > >"): {}
                    },
                    namespace("complex"): {
                        clike("struct", "Fold", template=["typename... Ts"]): {},
                        typedef("void_t", "void", template=["class..."]): {},
                        clike("struct", "has_type_member",
                              template=["class", "class=void"]): {},
                        clike("struct", "has_type_member< T, void_t< typename T::type > >",
                              template=["class T"]): {},
                        clike("struct", "IntPtr", template=["const int* I"]): {},
                        clike("struct", "IntRef", template=["const int& I"]): {}
                    }
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

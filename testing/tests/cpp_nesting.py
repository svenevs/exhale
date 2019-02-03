# -*- coding: utf8 -*-
########################################################################################
# This file is part of exhale.  Copyright (c) 2017-2019, Stephen McDowell.             #
# Full BSD 3-Clause license available here:                                            #
#                                                                                      #
#                https://github.com/svenevs/exhale/blob/master/LICENSE                 #
########################################################################################
"""
Tests for the ``cpp_nesting`` project.
"""

from __future__ import unicode_literals

from testing.base import ExhaleTestCase
from testing.decorators import confoverrides
from testing.hierarchies import                                              \
    class_hierarchy, clike, compare_class_hierarchy, compare_file_hierarchy, \
    directory, file, file_hierarchy, namespace, union


class CPPNesting(ExhaleTestCase):
    """
    Primary test class for project ``cpp_nesting``.
    """

    test_project = "cpp_nesting"
    """.. testproject:: cpp_nesting"""

    file_hierarchy_dict = {
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

    class_hierarchy_dict = {
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

    def test_hierarchies(self):
        """Verify the class and file hierarchies."""
        compare_file_hierarchy(self, file_hierarchy(self.file_hierarchy_dict))
        compare_class_hierarchy(self, class_hierarchy(self.class_hierarchy_dict))

    @confoverrides(exhale_args={"doxygenStripFromPath": "../include"})
    def test_hierarchies_stripped(self):
        """
        Verify the class and file hierarchies with ``doxygenStripFromPath=../include``.

        .. todo:: this test is not supported yet
        """
        return  # TODO: Exhale should remove the include/ directory
        # dirty hack to pop off the first include/ directory without needing to know
        # the actual object that is the first and only key
        for key in self.file_hierarchy_dict:
            no_include = self.file_hierarchy_dict[key]
            break
        compare_file_hierarchy(self, file_hierarchy(no_include))
        compare_class_hierarchy(self, class_hierarchy(self.class_hierarchy_dict))

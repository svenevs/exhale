########################################################################################
# This file is part of exhale.  Copyright (c) 2017-2018, Stephen McDowell.             #
# Full BSD 3-Clause license available here:                                            #
#                                                                                      #
#                https://github.com/svenevs/exhale/blob/master/LICENSE                 #
########################################################################################

"""
Tests for the ``cpp_nesting`` project.
"""

import os

from testing.base import ExhaleTestCase
from testing.decorators import confoverrides, no_cleanup, no_run
from testing.hierarchies import *


class CPPNesting(ExhaleTestCase):
    """
    Primary test class for project ``cpp_nesting``.
    """

    test_project = "cpp_nesting"
    """
    Index into ``testing/projects``.

    See also: :data:`testing.base.ExhaleTestCase.test_project`.
    """

    def test_app(self):
        """Simply checks :func:`testing.base.ExhaleTestCase.checkRequiredConfigs`."""
        self.checkRequiredConfigs()

    # @confoverrides(exhale_args={"doxygenStripFromPath": "../include"})
    @confoverrides(exhale_args={"createTreeView": True})
    # @no_cleanup
    def test_hierarchies(self):
        self.app.build()
        # the final exhale.graph.ExhaleRoot object
        exhale_root = self.app.exhale_root
        # verify the file hierarchy and file declaration relationships
        f_hierarchy = file_hierarchy({
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
                                }
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
        })
        compare_file_hierarchy(self, f_hierarchy, exhale_root)

        c_hierarchy = class_hierarchy({
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
        })
        compare_class_hierarchy(self, c_hierarchy, exhale_root)
        # # verify the class hierarchy and parental relationships
        # compare_class_hierarchy(self, {}, exhale_root)
        # verify_all_nodes_in_hierarchies()

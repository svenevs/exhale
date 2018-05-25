Testing Hierarchies Module
========================================================================================

.. automodule:: testing.hierarchies

.. contents:: Contents
   :local:
   :backlinks: none

Representing Hierarchies
----------------------------------------------------------------------------------------

.. graphviz::
   :align: center

   digraph G {
     rankdir="LR";
     ranksep=0.88;
     edge [dir=none];

     subgraph cluster_exhale {
       style=filled;
       color="#a2ddf9";
       label="Exhale Type";
       fontsize=22;
       node [style=filled, shape=rectangle, fontname="Courier"];
       e_fake_root_1 [style=none, shape=none, label=""];
       exhale_root [label="exhale.graph.ExhaleRoot"];
       e_fake_root_2 [style=none, shape=none, label=""];
     }

     subgraph cluster_testing {
       style=filled;
       color="#f7f389";
       label="Testing Types";
       fontsize=22;
       node [
         style=filled,
         shape=rectangle,
         fontname="Courier",
         width=2,
         fixedsize=true
       ];

       fake_root_1 [style=none, shape=none, label=""];
       hierarchy_root [label="hierarchies.root"];
       fake_root_2 [style=none, shape=none, label=""];
       file_hierarchy [label="file_hierarchy"];
       fake_hierarchy [style=none, shape=none, label=""];
       class_hierarchy [label="class_hierarchy"];


       hierarchy_root:e -> file_hierarchy:w;
       hierarchy_root -> fake_hierarchy [style=none, color=none];
       hierarchy_root:e -> class_hierarchy:w;

       {rank=same; fake_root_1; hierarchy_root; fake_root_2}
       {rank=same; class_hierarchy; fake_hierarchy; file_hierarchy}
     }

     exhale_root -> hierarchy_root [style=dashed, label="represents"];
   }

During normal execution, :class:`exhale.graph.ExhaleRoot` essentially represents
``index.xml`` coming from Doxygen.  The ``index.xml`` enumerates **far more** than what
the :class:`testing.hierarchies.root` class represents, the primary goal for the class
and file hierarchies is to validate generated (from Exhale) and expected (from the test)
output with respect to

**Name Scope Resolutions** (:class:`testing.hierarchies.class_hierarchy`)
    Particularly, parent-child relationships constructed in
    :class:`exhale.graph.ExhaleRoot`.  See :ref:`hierarchies_class_hierarchies`.

**Parsed Directory Structure** (:class:`testing.hierarchies.file_hierarchy`)
    Directory and file structure, **and** which file defines which documented construct.
    See :ref:`hierarchies_file_hierarchies`.

When creating a hierarchy to test, the author creates a json-like dictionary encoding
the expected relationships.  Generally, every helper class maps to a nested dictionary
value, with some exceptions:

.. graphviz::
   :align: center

   digraph G {
     rankdir="LR";
     ranksep=0.88;
     edge [dir=none];

     subgraph cluster_exhale {
       style=filled;
       color="#a2ddf9";
       label="Exhale Type";
       fontsize=22;
       node [style=filled, shape=rectangle, fontname="Courier"];
       subgraph cluster_hacksize {
        label=" ";// soooo hacky...
        fontsize=18;

       fake_node_1 [style=none, shape=none, label=""];
       fake_node_2 [style=none, shape=none, label=""];
       fake_node_3 [style=none, shape=none, label=""];
       fake_node_4 [style=none, shape=none, label=""];
       exhale_node [label="exhale.graph.ExhaleNode"];
       fake_node_5 [style=none, shape=none, label=""];
       fake_node_6 [style=none, shape=none, label=""];
       fake_node_7 [style=none, shape=none, label=""];
       fake_node_8 [style=none, shape=none, label=""];
       fake_node_9 [style=none, shape=none, label=""];
       }
     }

     subgraph cluster_testing {
       style=filled;
       color="#f7f389";
       label="Testing Types";
       fontsize=22;
       node [
         style=filled,
         shape=rectangle,
         fontname="Courier",
         width=2,
         fixedsize=true
       ];

       hierarchy_node [label="hierarchies.node"];

       subgraph cluster_keys {
         style=filled;
         color=cadetblue;
         label="Key Type";
         fontsize=18;

         clike;
         define;
         directory;
         enum;
         file;
         function;
         namespace;
         typedef;
         union;
         variable;
       }

       subgraph cluster_values {
         style=filled;
         color=mediumaquamarine;
         label="Value Type";
         fontsize=18;

         v_clike     [label="dict"];
         v_define    [label="????"];
         v_directory [label="dict"];
         v_enum      [label="????"];
         v_file      [label="dict"];
         v_function  [label="signature"];
         v_namespace [label="dict"];
         v_typedef   [label="????"];
         v_union     [label="dict"];
         v_variable  [label="????"];
       }

       hierarchy_node -> clike:w;
       hierarchy_node -> define:w;
       hierarchy_node -> directory:w;
       hierarchy_node -> enum:w;
       hierarchy_node -> file:w;
       hierarchy_node -> function:w;
       hierarchy_node -> namespace:w;
       hierarchy_node -> typedef:w;
       hierarchy_node -> union:w;
       hierarchy_node -> variable:w;

       clike     -> v_clike [dir=forward];
       define    -> v_define [dir=forward];
       directory -> v_directory [dir=forward];
       enum      -> v_enum [dir=forward];
       file      -> v_file  [dir=forward];
       function  -> v_function  [dir=forward];
       namespace -> v_namespace [dir=forward];
       typedef   -> v_typedef [dir=forward];
       union     -> v_union [dir=forward];
       variable  -> v_variable [dir=forward];


     }

     exhale_node -> hierarchy_node [dir=none];
     fake_node_1 -> clike [style=none, color=none];
   }

.. todo::

   ``????`` values indicate items not currently implemented or used in the testing
   framework.

.. autoclass:: testing.hierarchies.root
   :members:
   :special-members:
   :exclude-members: __init__, __weakref__, __dict__

.. _hierarchies_class_hierarchies:

Class Hierarchies
****************************************************************************************

.. autoclass:: testing.hierarchies.class_hierarchy
   :members:
   :special-members:
   :exclude-members: __init__, __weakref__, __dict__

.. autofunction:: testing.hierarchies.compare_class_hierarchy

.. _hierarchies_file_hierarchies:

File Hierarchies
****************************************************************************************

.. autoclass:: testing.hierarchies.file_hierarchy
   :members:
   :special-members:
   :exclude-members: __init__, __weakref__, __dict__

.. autofunction:: testing.hierarchies.compare_file_hierarchy


Utility Classes
----------------------------------------------------------------------------------------

.. autoclass:: testing.hierarchies.node
   :members:
   :special-members:
   :exclude-members: __init__, __weakref__, __dict__

Classes and Structs
****************************************************************************************

.. autoclass:: testing.hierarchies.clike
   :members:
   :special-members:
   :exclude-members: __init__, __weakref__, __dict__

Directories
****************************************************************************************

.. autoclass:: testing.hierarchies.directory
   :members:
   :special-members:
   :exclude-members: __init__, __weakref__, __dict__

Enums
****************************************************************************************

.. autoclass:: testing.hierarchies.enum
   :members:
   :special-members:
   :exclude-members: __init__, __weakref__, __dict__

Files
****************************************************************************************

.. autoclass:: testing.hierarchies.file
   :members:
   :special-members:
   :exclude-members: __init__, __weakref__, __dict__

Functions
****************************************************************************************

.. autoclass:: testing.hierarchies.function
   :members:
   :special-members:
   :exclude-members: __init__, __weakref__, __dict__

.. autoclass:: testing.hierarchies.signature
   :members:
   :special-members:
   :exclude-members: __init__, __weakref__, __dict__

Namespaces
****************************************************************************************

.. autoclass:: testing.hierarchies.namespace
   :members:
   :special-members:
   :exclude-members: __init__, __weakref__, __dict__

Unions
****************************************************************************************
.. autoclass:: testing.hierarchies.union
   :members:
   :special-members:
   :exclude-members: __init__, __weakref__, __dict__

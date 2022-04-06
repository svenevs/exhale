# -*- coding: utf8 -*-
########################################################################################
# This file is part of exhale.  Copyright (c) 2017-2022, Stephen McDowell.             #
# Full BSD 3-Clause license available here:                                            #
#                                                                                      #
#                https://github.com/svenevs/exhale/blob/master/LICENSE                 #
########################################################################################
"""
Tests specifically focused on the various tree view configurations.
"""
from __future__ import unicode_literals
import os
import re
from textwrap import dedent

from testing.base import ExhaleTestCase
from testing.decorators import confoverrides


class_hierarchy_ground_truth = {
    "default_rst_list": dedent(r'''
        - :ref:`namespace_nested`
            - :ref:`namespace_nested__dual_nested`
                - :ref:`exhale_struct_structnested_1_1dual__nested_1_1one`
                    - :ref:`exhale_struct_structnested_1_1dual__nested_1_1one_1_1params`
                        - :ref:`exhale_union_unionnested_1_1dual__nested_1_1one_1_1params_1_1four__bytes`
                - :ref:`exhale_struct_structnested_1_1dual__nested_1_1two`
                    - :ref:`exhale_struct_structnested_1_1dual__nested_1_1two_1_1params`
                        - :ref:`exhale_union_unionnested_1_1dual__nested_1_1two_1_1params_1_1four__bytes`
            - :ref:`exhale_struct_structnested_1_1one`
                - :ref:`exhale_struct_structnested_1_1one_1_1params`
                    - :ref:`exhale_union_unionnested_1_1one_1_1params_1_1four__bytes`
            - :ref:`exhale_struct_structnested_1_1two`
                - :ref:`exhale_struct_structnested_1_1two_1_1params`
                    - :ref:`exhale_union_unionnested_1_1two_1_1params_1_1four__bytes`
            - :ref:`exhale_union_unionnested_1_1four__bytes`
        - :ref:`namespace_special`
            - :ref:`exhale_struct_structspecial_1_1_base`
                - :ref:`exhale_struct_structspecial_1_1_base_1_1_a`
            - :ref:`exhale_struct_structspecial_1_1_base_3_012_01_4`
                - :ref:`exhale_struct_structspecial_1_1_base_3_012_01_4_1_1_another_nested_struct`
                - :ref:`exhale_struct_structspecial_1_1_base_3_012_01_4_1_1_inner_struct`
                - :ref:`exhale_struct_structspecial_1_1_base_3_012_01_4_1_1_inner_templated_struct`
                - :ref:`exhale_struct_structspecial_1_1_base_3_012_01_4_1_1_inner_templated_struct_3_014_00_01dont__use__this_01_4`
            - :ref:`exhale_struct_structspecial_1_1_image`
            - :ref:`exhale_struct_structspecial_1_1_normal`
                - :ref:`exhale_struct_structspecial_1_1_normal_1_1_nested`
                    - :ref:`exhale_struct_structspecial_1_1_normal_1_1_nested_1_1_like`
                        - :ref:`exhale_struct_structspecial_1_1_normal_1_1_nested_1_1_like_1_1_usual`
            - :ref:`exhale_class_classspecial_1_1_image_buffer`
                - :ref:`exhale_struct_structspecial_1_1_image_buffer_1_1_data`
                - :ref:`exhale_struct_structspecial_1_1_image_buffer_1_1_some_thing`
            - :ref:`exhale_class_classspecial_1_1_image_buffer_3_01_image_3_011920_00_011080_01_4_00_01float_00_01128_01_4`
                - :ref:`exhale_struct_structspecial_1_1_image_buffer_3_01_image_3_011920_00_011080_01_4_00_01float_00_01128_01_4_1_1_data`
                - :ref:`exhale_struct_structspecial_1_1_image_buffer_3_01_image_3_011920_00_011080_01_4_00_01float_00_01128_01_4_1_1_some_thing`
            - :ref:`exhale_class_classspecial_1_1_image_buffer_3_01_t_image_00_01_tdata__t_00_014_01_4`
                - :ref:`exhale_struct_structspecial_1_1_image_buffer_3_01_t_image_00_01_tdata__t_00_014_01_4_1_1_data`
                - :ref:`exhale_struct_structspecial_1_1_image_buffer_3_01_t_image_00_01_tdata__t_00_014_01_4_1_1_some_thing`
        - :ref:`exhale_struct_structtop__level`
    '''),
    "collapsible_lists": dedent(r'''
        <ul class="treeView" id="class-treeView">
     <li>
       <ul class="collapsibleList">
         <li>
           Namespace <a href="namespace_nested.html#namespace-nested">nested</a>
           <ul>
             <li>
               Namespace <a href="namespace_nested__dual_nested.html#namespace-nested-dual-nested">nested::dual_nested</a>
               <ul>
                 <li>
                   Struct <a href="structnested_1_1dual__nested_1_1one.html#exhale-struct-structnested-1-1dual-nested-1-1one">one</a>
                   <ul>
                     <li class="lastChild">
                       Struct <a href="structnested_1_1dual__nested_1_1one_1_1params.html#exhale-struct-structnested-1-1dual-nested-1-1one-1-1params">one::params</a>
                       <ul>
                         <li class="lastChild">Union <a href="unionnested_1_1dual__nested_1_1one_1_1params_1_1four__bytes.html#exhale-union-unionnested-1-1dual-nested-1-1one-1-1params-1-1four-bytes">params::four_bytes</a></li>
                       </ul>
                     </li>
                   </ul>
                 </li>
                 <li class="lastChild">
                   Struct <a href="structnested_1_1dual__nested_1_1two.html#exhale-struct-structnested-1-1dual-nested-1-1two">two</a>
                   <ul>
                     <li class="lastChild">
                       Struct <a href="structnested_1_1dual__nested_1_1two_1_1params.html#exhale-struct-structnested-1-1dual-nested-1-1two-1-1params">two::params</a>
                       <ul>
                         <li class="lastChild">Union <a href="unionnested_1_1dual__nested_1_1two_1_1params_1_1four__bytes.html#exhale-union-unionnested-1-1dual-nested-1-1two-1-1params-1-1four-bytes">params::four_bytes</a></li>
                       </ul>
                     </li>
                   </ul>
                 </li>
               </ul>
             </li>
             <li>
               Struct <a href="structnested_1_1one.html#exhale-struct-structnested-1-1one">one</a>
               <ul>
                 <li class="lastChild">
                   Struct <a href="structnested_1_1one_1_1params.html#exhale-struct-structnested-1-1one-1-1params">one::params</a>
                   <ul>
                     <li class="lastChild">Union <a href="unionnested_1_1one_1_1params_1_1four__bytes.html#exhale-union-unionnested-1-1one-1-1params-1-1four-bytes">params::four_bytes</a></li>
                   </ul>
                 </li>
               </ul>
             </li>
             <li>
               Struct <a href="structnested_1_1two.html#exhale-struct-structnested-1-1two">two</a>
               <ul>
                 <li class="lastChild">
                   Struct <a href="structnested_1_1two_1_1params.html#exhale-struct-structnested-1-1two-1-1params">two::params</a>
                   <ul>
                     <li class="lastChild">Union <a href="unionnested_1_1two_1_1params_1_1four__bytes.html#exhale-union-unionnested-1-1two-1-1params-1-1four-bytes">params::four_bytes</a></li>
                   </ul>
                 </li>
               </ul>
             </li>
             <li class="lastChild">Union <a href="unionnested_1_1four__bytes.html#exhale-union-unionnested-1-1four-bytes">four_bytes</a></li>
           </ul>
         </li>
         <li>
           Namespace <a href="namespace_special.html#namespace-special">special</a>
           <ul>
             <li>
               Template Struct <a href="structspecial_1_1_base.html#exhale-struct-structspecial-1-1-base">Base</a>
               <ul>
                 <li class="lastChild">Struct <a href="structspecial_1_1_base_1_1_a.html#exhale-struct-structspecial-1-1-base-1-1-a">Base::A</a></li>
               </ul>
             </li>
             <li>
               Template <a href="structspecial_1_1_base_3_012_01_4.html#exhale-struct-structspecial-1-1-base-3-012-01-4">Struct Base&lt;2&gt;</a>
               <ul>
                 <li>Template <a href="structspecial_1_1_base_3_012_01_4_1_1_another_nested_struct.html#exhale-struct-structspecial-1-1-base-3-012-01-4-1-1-another-nested-struct">Struct Base&lt; 2 &gt;::AnotherNestedStruct</a></li>
                 <li>Template <a href="structspecial_1_1_base_3_012_01_4_1_1_inner_struct.html#exhale-struct-structspecial-1-1-base-3-012-01-4-1-1-inner-struct">Struct Base&lt; 2 &gt;::InnerStruct</a></li>
                 <li>Template <a href="structspecial_1_1_base_3_012_01_4_1_1_inner_templated_struct.html#exhale-struct-structspecial-1-1-base-3-012-01-4-1-1-inner-templated-struct">Struct Base&lt; 2 &gt;::InnerTemplatedStruct</a></li>
                 <li class="lastChild">Template <a href="structspecial_1_1_base_3_012_01_4_1_1_inner_templated_struct_3_014_00_01dont__use__this_01_4.html#exhale-struct-structspecial-1-1-base-3-012-01-4-1-1-inner-templated-struct-3-014-00-01dont-use-this-01-4">Struct Base&lt; 2 &gt;::InnerTemplatedStruct&lt;4, dont_use_this&gt;</a></li>
               </ul>
             </li>
             <li>Template Struct <a href="structspecial_1_1_image.html#exhale-struct-structspecial-1-1-image">Image</a></li>
             <li>
               Struct <a href="structspecial_1_1_normal.html#exhale-struct-structspecial-1-1-normal">Normal</a>
               <ul>
                 <li class="lastChild">
                   Struct <a href="structspecial_1_1_normal_1_1_nested.html#exhale-struct-structspecial-1-1-normal-1-1-nested">Normal::Nested</a>
                   <ul>
                     <li class="lastChild">
                       Struct <a href="structspecial_1_1_normal_1_1_nested_1_1_like.html#exhale-struct-structspecial-1-1-normal-1-1-nested-1-1-like">Nested::Like</a>
                       <ul>
                         <li class="lastChild">Struct <a href="structspecial_1_1_normal_1_1_nested_1_1_like_1_1_usual.html#exhale-struct-structspecial-1-1-normal-1-1-nested-1-1-like-1-1-usual">Like::Usual</a></li>
                       </ul>
                     </li>
                   </ul>
                 </li>
               </ul>
             </li>
             <li>
               Template Class <a href="classspecial_1_1_image_buffer.html#exhale-class-classspecial-1-1-image-buffer">ImageBuffer</a>
               <ul>
                 <li>Struct <a href="structspecial_1_1_image_buffer_1_1_data.html#exhale-struct-structspecial-1-1-image-buffer-1-1-data">ImageBuffer::Data</a></li>
                 <li class="lastChild">Template Struct <a href="structspecial_1_1_image_buffer_1_1_some_thing.html#exhale-struct-structspecial-1-1-image-buffer-1-1-some-thing">ImageBuffer::SomeThing</a></li>
               </ul>
             </li>
             <li>
               Template <a href="classspecial_1_1_image_buffer_3_01_image_3_011920_00_011080_01_4_00_01float_00_01128_01_4.html#exhale-class-classspecial-1-1-image-buffer-3-01-image-3-011920-00-011080-01-4-00-01float-00-01128-01-4">Class ImageBuffer&lt;Image&lt;1920, 1080&gt;float, 128&gt;</a>
               <ul>
                 <li>Template <a href="structspecial_1_1_image_buffer_3_01_image_3_011920_00_011080_01_4_00_01float_00_01128_01_4_1_1_data.html#exhale-struct-structspecial-1-1-image-buffer-3-01-image-3-011920-00-011080-01-4-00-01float-00-01128-01-4-1-1-data">Struct ImageBuffer&lt; Image&lt; 1920, 1080 &gt;, float, 128 &gt;::Data</a></li>
                 <li class="lastChild">Template <a href="structspecial_1_1_image_buffer_3_01_image_3_011920_00_011080_01_4_00_01float_00_01128_01_4_1_1_some_thing.html#exhale-struct-structspecial-1-1-image-buffer-3-01-image-3-011920-00-011080-01-4-00-01float-00-01128-01-4-1-1-some-thing">Struct ImageBuffer&lt; Image&lt; 1920, 1080 &gt;, float, 128 &gt;::SomeThing</a></li>
               </ul>
             </li>
             <li class="lastChild">
               Template Class <a href="classspecial_1_1_image_buffer_3_01_t_image_00_01_tdata__t_00_014_01_4.html#exhale-class-classspecial-1-1-image-buffer-3-01-t-image-00-01-tdata-t-00-014-01-4">ImageBuffer&lt;TImage, Tdata_t, 4&gt;</a>
               <ul>
                 <li>Template <a href="structspecial_1_1_image_buffer_3_01_t_image_00_01_tdata__t_00_014_01_4_1_1_data.html#exhale-struct-structspecial-1-1-image-buffer-3-01-t-image-00-01-tdata-t-00-014-01-4-1-1-data">Struct ImageBuffer&lt; TImage, Tdata_t, 4 &gt;::Data</a></li>
                 <li class="lastChild">Template <a href="structspecial_1_1_image_buffer_3_01_t_image_00_01_tdata__t_00_014_01_4_1_1_some_thing.html#exhale-struct-structspecial-1-1-image-buffer-3-01-t-image-00-01-tdata-t-00-014-01-4-1-1-some-thing">Struct ImageBuffer&lt; TImage, Tdata_t, 4 &gt;::SomeThing</a></li>
               </ul>
             </li>
           </ul>
         </li>
         <li class="lastChild">Struct <a href="structtop__level.html#exhale-struct-structtop-level">top_level</a></li>

       </ul>
     </li><!-- only tree view element -->
   </ul><!-- /treeView class-treeView -->
    '''),  # noqa: E501
    "bootstrap": dedent(r'''
        <div id="class-treeView"></div>
           <script type="text/javascript">
            function getClassHierarchyTree() {
               return [
                {
                  text: "<span class=\"text-muted\">Namespace</span> nested",
                  href: "namespace_nested.html#namespace-nested",
                  selectable: false,
                  tags: ['4'],
        
                  nodes: [
                    {
                      text: "<span class=\"text-muted\">Namespace</span> nested::dual_nested",
                      href: "namespace_nested__dual_nested.html#namespace-nested-dual-nested",
                      selectable: false,
                      tags: ['2'],
        
                      nodes: [
                        {
                          text: "<span class=\"text-muted\">Struct</span> one",
                          href: "structnested_1_1dual__nested_1_1one.html#exhale-struct-structnested-1-1dual-nested-1-1one",
                          selectable: false,
                          tags: ['1'],
        
                          nodes: [
                            {
                              text: "<span class=\"text-muted\">Struct</span> one::params",
                              href: "structnested_1_1dual__nested_1_1one_1_1params.html#exhale-struct-structnested-1-1dual-nested-1-1one-1-1params",
                              selectable: false,
                              tags: ['1'],
        
                              nodes: [
                                {
                                  text: "<span class=\"text-muted\">Union</span> params::four_bytes",
                                  href: "unionnested_1_1dual__nested_1_1one_1_1params_1_1four__bytes.html#exhale-union-unionnested-1-1dual-nested-1-1one-1-1params-1-1four-bytes",
                                  selectable: false,
                                },
                              ]
                            },
                          ]
                        },
                        {
                          text: "<span class=\"text-muted\">Struct</span> two",
                          href: "structnested_1_1dual__nested_1_1two.html#exhale-struct-structnested-1-1dual-nested-1-1two",
                          selectable: false,
                          tags: ['1'],
        
                          nodes: [
                            {
                              text: "<span class=\"text-muted\">Struct</span> two::params",
                              href: "structnested_1_1dual__nested_1_1two_1_1params.html#exhale-struct-structnested-1-1dual-nested-1-1two-1-1params",
                              selectable: false,
                              tags: ['1'],
        
                              nodes: [
                                {
                                  text: "<span class=\"text-muted\">Union</span> params::four_bytes",
                                  href: "unionnested_1_1dual__nested_1_1two_1_1params_1_1four__bytes.html#exhale-union-unionnested-1-1dual-nested-1-1two-1-1params-1-1four-bytes",
                                  selectable: false,
                                },
                              ]
                            },
                          ]
                        },
                      ]
                    },
                    {
                      text: "<span class=\"text-muted\">Struct</span> one",
                      href: "structnested_1_1one.html#exhale-struct-structnested-1-1one",
                      selectable: false,
                      tags: ['1'],
        
                      nodes: [
                        {
                          text: "<span class=\"text-muted\">Struct</span> one::params",
                          href: "structnested_1_1one_1_1params.html#exhale-struct-structnested-1-1one-1-1params",
                          selectable: false,
                          tags: ['1'],
        
                          nodes: [
                            {
                              text: "<span class=\"text-muted\">Union</span> params::four_bytes",
                              href: "unionnested_1_1one_1_1params_1_1four__bytes.html#exhale-union-unionnested-1-1one-1-1params-1-1four-bytes",
                              selectable: false,
                            },
                          ]
                        },
                      ]
                    },
                    {
                      text: "<span class=\"text-muted\">Struct</span> two",
                      href: "structnested_1_1two.html#exhale-struct-structnested-1-1two",
                      selectable: false,
                      tags: ['1'],
        
                      nodes: [
                        {
                          text: "<span class=\"text-muted\">Struct</span> two::params",
                          href: "structnested_1_1two_1_1params.html#exhale-struct-structnested-1-1two-1-1params",
                          selectable: false,
                          tags: ['1'],
        
                          nodes: [
                            {
                              text: "<span class=\"text-muted\">Union</span> params::four_bytes",
                              href: "unionnested_1_1two_1_1params_1_1four__bytes.html#exhale-union-unionnested-1-1two-1-1params-1-1four-bytes",
                              selectable: false,
                            },
                          ]
                        },
                      ]
                    },
                    {
                      text: "<span class=\"text-muted\">Union</span> four_bytes",
                      href: "unionnested_1_1four__bytes.html#exhale-union-unionnested-1-1four-bytes",
                      selectable: false,
                    },
                  ]
                },
                {
                  text: "<span class=\"text-muted\">Namespace</span> special",
                  href: "namespace_special.html#namespace-special",
                  selectable: false,
                  tags: ['7'],
        
                  nodes: [
                    {
                      text: "<span class=\"text-muted\">Template Struct</span> Base",
                      href: "structspecial_1_1_base.html#exhale-struct-structspecial-1-1-base",
                      selectable: false,
                      tags: ['1'],
        
                      nodes: [
                        {
                          text: "<span class=\"text-muted\">Struct</span> Base::A",
                          href: "structspecial_1_1_base_1_1_a.html#exhale-struct-structspecial-1-1-base-1-1-a",
                          selectable: false,
                        },
                      ]
                    },
                    {
                      text: "<span class=\"text-muted\">Template</span> Struct Base&lt;2&gt;",
                      href: "structspecial_1_1_base_3_012_01_4.html#exhale-struct-structspecial-1-1-base-3-012-01-4",
                      selectable: false,
                      tags: ['4'],
        
                      nodes: [
                        {
                          text: "<span class=\"text-muted\">Template</span> Struct Base&lt; 2 &gt;::AnotherNestedStruct",
                          href: "structspecial_1_1_base_3_012_01_4_1_1_another_nested_struct.html#exhale-struct-structspecial-1-1-base-3-012-01-4-1-1-another-nested-struct",
                          selectable: false,
                        },
                        {
                          text: "<span class=\"text-muted\">Template</span> Struct Base&lt; 2 &gt;::InnerStruct",
                          href: "structspecial_1_1_base_3_012_01_4_1_1_inner_struct.html#exhale-struct-structspecial-1-1-base-3-012-01-4-1-1-inner-struct",
                          selectable: false,
                        },
                        {
                          text: "<span class=\"text-muted\">Template</span> Struct Base&lt; 2 &gt;::InnerTemplatedStruct",
                          href: "structspecial_1_1_base_3_012_01_4_1_1_inner_templated_struct.html#exhale-struct-structspecial-1-1-base-3-012-01-4-1-1-inner-templated-struct",
                          selectable: false,
                        },
                        {
                          text: "<span class=\"text-muted\">Template</span> Struct Base&lt; 2 &gt;::InnerTemplatedStruct&lt;4, dont_use_this&gt;",
                          href: "structspecial_1_1_base_3_012_01_4_1_1_inner_templated_struct_3_014_00_01dont__use__this_01_4.html#exhale-struct-structspecial-1-1-base-3-012-01-4-1-1-inner-templated-struct-3-014-00-01dont-use-this-01-4",
                          selectable: false,
                        },
                      ]
                    },
                    {
                      text: "<span class=\"text-muted\">Template Struct</span> Image",
                      href: "structspecial_1_1_image.html#exhale-struct-structspecial-1-1-image",
                      selectable: false,
                    },
                    {
                      text: "<span class=\"text-muted\">Struct</span> Normal",
                      href: "structspecial_1_1_normal.html#exhale-struct-structspecial-1-1-normal",
                      selectable: false,
                      tags: ['1'],
        
                      nodes: [
                        {
                          text: "<span class=\"text-muted\">Struct</span> Normal::Nested",
                          href: "structspecial_1_1_normal_1_1_nested.html#exhale-struct-structspecial-1-1-normal-1-1-nested",
                          selectable: false,
                          tags: ['1'],
        
                          nodes: [
                            {
                              text: "<span class=\"text-muted\">Struct</span> Nested::Like",
                              href: "structspecial_1_1_normal_1_1_nested_1_1_like.html#exhale-struct-structspecial-1-1-normal-1-1-nested-1-1-like",
                              selectable: false,
                              tags: ['1'],
        
                              nodes: [
                                {
                                  text: "<span class=\"text-muted\">Struct</span> Like::Usual",
                                  href: "structspecial_1_1_normal_1_1_nested_1_1_like_1_1_usual.html#exhale-struct-structspecial-1-1-normal-1-1-nested-1-1-like-1-1-usual",
                                  selectable: false,
                                },
                              ]
                            },
                          ]
                        },
                      ]
                    },
                    {
                      text: "<span class=\"text-muted\">Template Class</span> ImageBuffer",
                      href: "classspecial_1_1_image_buffer.html#exhale-class-classspecial-1-1-image-buffer",
                      selectable: false,
                      tags: ['2'],
        
                      nodes: [
                        {
                          text: "<span class=\"text-muted\">Struct</span> ImageBuffer::Data",
                          href: "structspecial_1_1_image_buffer_1_1_data.html#exhale-struct-structspecial-1-1-image-buffer-1-1-data",
                          selectable: false,
                        },
                        {
                          text: "<span class=\"text-muted\">Template Struct</span> ImageBuffer::SomeThing",
                          href: "structspecial_1_1_image_buffer_1_1_some_thing.html#exhale-struct-structspecial-1-1-image-buffer-1-1-some-thing",
                          selectable: false,
                        },
                      ]
                    },
                    {
                      text: "<span class=\"text-muted\">Template</span> Class ImageBuffer&lt;Image&lt;1920, 1080&gt;float, 128&gt;",
                      href: "classspecial_1_1_image_buffer_3_01_image_3_011920_00_011080_01_4_00_01float_00_01128_01_4.html#exhale-class-classspecial-1-1-image-buffer-3-01-image-3-011920-00-011080-01-4-00-01float-00-01128-01-4",
                      selectable: false,
                      tags: ['2'],
        
                      nodes: [
                        {
                          text: "<span class=\"text-muted\">Template</span> Struct ImageBuffer&lt; Image&lt; 1920, 1080 &gt;, float, 128 &gt;::Data",
                          href: "structspecial_1_1_image_buffer_3_01_image_3_011920_00_011080_01_4_00_01float_00_01128_01_4_1_1_data.html#exhale-struct-structspecial-1-1-image-buffer-3-01-image-3-011920-00-011080-01-4-00-01float-00-01128-01-4-1-1-data",
                          selectable: false,
                        },
                        {
                          text: "<span class=\"text-muted\">Template</span> Struct ImageBuffer&lt; Image&lt; 1920, 1080 &gt;, float, 128 &gt;::SomeThing",
                          href: "structspecial_1_1_image_buffer_3_01_image_3_011920_00_011080_01_4_00_01float_00_01128_01_4_1_1_some_thing.html#exhale-struct-structspecial-1-1-image-buffer-3-01-image-3-011920-00-011080-01-4-00-01float-00-01128-01-4-1-1-some-thing",
                          selectable: false,
                        },
                      ]
                    },
                    {
                      text: "<span class=\"text-muted\">Template Class</span> ImageBuffer&lt;TImage, Tdata_t, 4&gt;",
                      href: "classspecial_1_1_image_buffer_3_01_t_image_00_01_tdata__t_00_014_01_4.html#exhale-class-classspecial-1-1-image-buffer-3-01-t-image-00-01-tdata-t-00-014-01-4",
                      selectable: false,
                      tags: ['2'],
        
                      nodes: [
                        {
                          text: "<span class=\"text-muted\">Template</span> Struct ImageBuffer&lt; TImage, Tdata_t, 4 &gt;::Data",
                          href: "structspecial_1_1_image_buffer_3_01_t_image_00_01_tdata__t_00_014_01_4_1_1_data.html#exhale-struct-structspecial-1-1-image-buffer-3-01-t-image-00-01-tdata-t-00-014-01-4-1-1-data",
                          selectable: false,
                        },
                        {
                          text: "<span class=\"text-muted\">Template</span> Struct ImageBuffer&lt; TImage, Tdata_t, 4 &gt;::SomeThing",
                          href: "structspecial_1_1_image_buffer_3_01_t_image_00_01_tdata__t_00_014_01_4_1_1_some_thing.html#exhale-struct-structspecial-1-1-image-buffer-3-01-t-image-00-01-tdata-t-00-014-01-4-1-1-some-thing",
                          selectable: false,
                        },
                      ]
                    },
                  ]
                },
                {
                  text: "<span class=\"text-muted\">Struct</span> top_level",
                  href: "structtop__level.html#exhale-struct-structtop-level",
                  selectable: false,
                },
        
               ]
            }
       </script><!-- end getClassHierarchyTree() function -->
    ''')  # noqa: E501
}
"""
Ground truth for the three versions of class hierarchies.

Keys and what they represent:

``"default_rst_list"``
    The reStructuredText list version (``createTreeView=False``).

``"collapsible_lists"``
    The collapsible lists version of the tree view (raw html unordered list).

``"bootstrap"``
    The bootstrap version of the tree view (raw JavaScript function returning json data).

.. todo::

    This will break if / when doxygen refid generation changes.  In theory it should be
    possible to synthetically re-create the hierarchy without this crazy text processing.
"""


file_hierarchy_ground_truth = {
    "default_rst_list": dedent(r'''
        - :ref:`dir_include`
            - :ref:`dir_include_nested`
                - :ref:`dir_include_nested_dual_nested`
                    - :ref:`dir_include_nested_dual_nested_one`
                        - :ref:`file_include_nested_dual_nested_one_one.hpp`
                    - :ref:`dir_include_nested_dual_nested_two`
                        - :ref:`file_include_nested_dual_nested_two_two.hpp`
                - :ref:`dir_include_nested_one`
                    - :ref:`file_include_nested_one_one.hpp`
                - :ref:`dir_include_nested_two`
                    - :ref:`file_include_nested_two_two.hpp`
            - :ref:`file_include_nesting_specializations.hpp`
            - :ref:`file_include_top_level.hpp`
    '''),
    "collapsible_lists": dedent(r'''
        <ul class="treeView" id="file-treeView">
     <li>
       <ul class="collapsibleList">
         <li class="lastChild">
           Directory <a href="dir_include.html#dir-include">include</a>
           <ul>
             <li>
               Directory <a href="dir_include_nested.html#dir-include-nested">nested</a>
               <ul>
                 <li>
                   Directory <a href="dir_include_nested_dual_nested.html#dir-include-nested-dual-nested">dual_nested</a>
                   <ul>
                     <li>
                       Directory <a href="dir_include_nested_dual_nested_one.html#dir-include-nested-dual-nested-one">one</a>
                       <ul>
                         <li class="lastChild">File <a href="file_include_nested_dual_nested_one_one.hpp.html#file-include-nested-dual-nested-one-one.hpp">one.hpp</a></li>
                       </ul>
                     </li>
                     <li class="lastChild">
                       Directory <a href="dir_include_nested_dual_nested_two.html#dir-include-nested-dual-nested-two">two</a>
                       <ul>
                         <li class="lastChild">File <a href="file_include_nested_dual_nested_two_two.hpp.html#file-include-nested-dual-nested-two-two.hpp">two.hpp</a></li>
                       </ul>
                     </li>
                   </ul>
                 </li>
                 <li>
                   Directory <a href="dir_include_nested_one.html#dir-include-nested-one">one</a>
                   <ul>
                     <li class="lastChild">File <a href="file_include_nested_one_one.hpp.html#file-include-nested-one-one.hpp">one.hpp</a></li>
                   </ul>
                 </li>
                 <li class="lastChild">
                   Directory <a href="dir_include_nested_two.html#dir-include-nested-two">two</a>
                   <ul>
                     <li class="lastChild">File <a href="file_include_nested_two_two.hpp.html#file-include-nested-two-two.hpp">two.hpp</a></li>
                   </ul>
                 </li>
               </ul>
             </li>
             <li>File <a href="file_include_nesting_specializations.hpp.html#file-include-nesting-specializations.hpp">nesting_specializations.hpp</a></li>
             <li class="lastChild">File <a href="file_include_top_level.hpp.html#file-include-top-level.hpp">top_level.hpp</a></li>
           </ul>
         </li>

       </ul>
     </li><!-- only tree view element -->
   </ul><!-- /treeView file-treeView -->
    '''),  # noqa: E501
    "bootstrap": dedent(r'''
        <div id="file-treeView"></div>
       <script type="text/javascript">
         function getFileHierarchyTree() {
            return [
             {
               text: "<span class=\"text-muted\">Directory</span> include",
               href: "dir_include.html#dir-include",
               selectable: false,
               tags: ['3'],
    
               nodes: [
                 {
                   text: "<span class=\"text-muted\">Directory</span> nested",
                   href: "dir_include_nested.html#dir-include-nested",
                   selectable: false,
                   tags: ['3'],
    
                   nodes: [
                     {
                       text: "<span class=\"text-muted\">Directory</span> dual_nested",
                       href: "dir_include_nested_dual_nested.html#dir-include-nested-dual-nested",
                       selectable: false,
                       tags: ['2'],
    
                       nodes: [
                         {
                           text: "<span class=\"text-muted\">Directory</span> one",
                           href: "dir_include_nested_dual_nested_one.html#dir-include-nested-dual-nested-one",
                           selectable: false,
                           tags: ['1'],
    
                           nodes: [
                             {
                               text: "<span class=\"text-muted\">File</span> one.hpp",
                               href: "file_include_nested_dual_nested_one_one.hpp.html#file-include-nested-dual-nested-one-one.hpp",
                               selectable: false,
                             },
                           ]
                         },
                         {
                           text: "<span class=\"text-muted\">Directory</span> two",
                           href: "dir_include_nested_dual_nested_two.html#dir-include-nested-dual-nested-two",
                           selectable: false,
                           tags: ['1'],
    
                           nodes: [
                             {
                               text: "<span class=\"text-muted\">File</span> two.hpp",
                               href: "file_include_nested_dual_nested_two_two.hpp.html#file-include-nested-dual-nested-two-two.hpp",
                               selectable: false,
                             },
                           ]
                         },
                       ]
                     },
                     {
                       text: "<span class=\"text-muted\">Directory</span> one",
                       href: "dir_include_nested_one.html#dir-include-nested-one",
                       selectable: false,
                       tags: ['1'],
    
                       nodes: [
                         {
                           text: "<span class=\"text-muted\">File</span> one.hpp",
                           href: "file_include_nested_one_one.hpp.html#file-include-nested-one-one.hpp",
                           selectable: false,
                         },
                       ]
                     },
                     {
                       text: "<span class=\"text-muted\">Directory</span> two",
                       href: "dir_include_nested_two.html#dir-include-nested-two",
                       selectable: false,
                       tags: ['1'],
    
                       nodes: [
                         {
                           text: "<span class=\"text-muted\">File</span> two.hpp",
                           href: "file_include_nested_two_two.hpp.html#file-include-nested-two-two.hpp",
                           selectable: false,
                         },
                       ]
                     },
                   ]
                 },
                 {
                   text: "<span class=\"text-muted\">File</span> nesting_specializations.hpp",
                   href: "file_include_nesting_specializations.hpp.html#file-include-nesting-specializations.hpp",
                   selectable: false,
                 },
                 {
                   text: "<span class=\"text-muted\">File</span> top_level.hpp",
                   href: "file_include_top_level.hpp.html#file-include-top-level.hpp",
                   selectable: false,
                 },
               ]
             },
    
            ]
         }
   </script><!-- end getFileHierarchyTree() function -->
    ''')  # noqa: E501
}
"""
Ground truth for the three versions of file hierarchies.

Keys and what they represent:

``"default_rst_list"``
    The reStructuredText list version (``createTreeView=False``).

``"collapsible_lists"``
    The collapsible lists version of the tree view (raw html unordered list).

``"bootstrap"``
    The bootstrap version of the tree view (raw JavaScript function returning json data).

.. todo::

   This one should be possible to re-create manually rather than relying on direct text
   comparisons.  But until you figure out how to do the class one more programmatically
   you aren't doing that lolz.
"""


# NOTE: See cpp_nesting.CPPNestingPages.{setUp,tearDown} (creates page_town_rock.hpp).
@confoverrides(exhale_args={
    "exhaleDoxygenStdin": dedent("""\
        INPUT            = ../include
        EXCLUDE_PATTERNS = */page_town_rock*.hpp
    """)})
class TreeViewHierarchyTests(ExhaleTestCase):
    """
    Naive tests on raw "reStructuredText" generated for tree views.
    """

    test_project = "cpp_nesting"
    """
    .. testproject:: cpp_nesting

    .. note::

        The ``cpp_nesting`` project is just being recycled, the tests for that project
        take place in
        :class:`CPPNesting <testing.tests.cpp_nesting.CPPNesting>`.
    """

    def class_view_hierarchy_file(self):
        """Path to ``class_view_hierarchy.rst.include`` for this test."""
        return os.path.join(
            self.getAbsContainmentFolder(), "class_view_hierarchy.rst.include")

    def file_view_hierarchy_file(self):
        """Path to ``file_view_hierarchy.rst.include`` for this test."""
        return os.path.join(
            self.getAbsContainmentFolder(), "file_view_hierarchy.rst.include")

    def raw_hierarchies(self):
        """
        Raw contents of ``{class,file}_view_hierarchy.rst.include``.

        **Return** (Length ``2`` :class:`python:tuple` of :class:`python:str`)
            The string contents of ``(class_view, file_view)``, in that order.
        """
        with open(self.class_view_hierarchy_file()) as class_view:
            class_view_contents = class_view.read()

        with open(self.file_view_hierarchy_file()) as file_view:
            file_view_contents = file_view.read()

        return (class_view_contents, file_view_contents)

    def filter_empty_lines(self, lst):
        """
        Return a copy of ``lst`` with empty / whitespace-only strings removed.

        **Parameters**
            ``lst`` (:class:`python:list` of :class:`python:str`)
                The input list of strings to filter.

        **Return** (:class:`python:list` of :class:`python:str`)
            The input ``lst`` in the same order, with empty strings and whitespace-only
            strings removed.
        """
        empty_or_whitespace = re.compile(r"^$|^\s+$")
        return [line for line in lst if not empty_or_whitespace.match(line)]

    def html_hierarchies(self):
        """
        Hierarchy text from ``{class,file}_view_hierarchy.rst``.

        When ``createTreeView=True``, the generated page has something like:

        .. code-block:: rst

            Class View Hierarchy
            --------------------

            .. raw:: html

               <ul>
                 <li> ... </li>
                 <!-- ... -->
                 <li> ... </li>
               </ul>

            .. end raw html for treeView

        What this method does is simply search for ``.. raw:: html`` and ``.. end``
        respectively, accumulating everything in between.  Since we are performing
        direct string comparisons with "ground truth" values, we specifically accumulate
        ``line.strip()`` to remove the leading indentation since it is under a
        ``.. raw:: html`` directive.  Finally, the returned output is filtered using
        :func:`filter_empty_lines`.

        **Return** (Length ``2`` :class:`python:tuple` of :class:`python:list` of :class:`python:str`)
            A length two tuple in the order ``(class_view, file_view)``.  Each item in
            the tuple is a list of strings of the parsed / filtered lines.
        """
        def strip_html_directive(hierarchy):
            hierarchy_lines = []
            found_raw_html = False
            for line in hierarchy.splitlines():
                if found_raw_html:
                    if line.startswith(".. end"):
                        break
                    hierarchy_lines.append(line.strip())
                elif line.startswith(".. raw:: html"):
                    found_raw_html = True

            return self.filter_empty_lines(hierarchy_lines)

        class_view_raw, file_view_raw = self.raw_hierarchies()
        return (strip_html_directive(class_view_raw), strip_html_directive(file_view_raw))

    def line_compare(self, expected_list, test_list):
        """
        Compare two lists of strings.

        Performs two tests:

        1. That ``len(expected_list)`` and ``len(test_list)`` are the same.
        2. That the order and values of strings in ``expected_list`` are the same as
           ``test_list``.  Mismatched values will be printed in the assertion.

        **Parameters**
            ``expected_list`` (:class:`python:list` of :class:`python:str`)
                The expected list of strings to compare with.

            ``test_list`` (:class:`python:list` of :class:`python:str`)
                The parsed list of strings to validate.
        """
        num_expected_lines = len(expected_list)
        self.assertEqual(num_expected_lines, len(test_list))

        mismatches = []
        for idx in range(num_expected_lines):
            expected = expected_list[idx]
            test = test_list[idx]
            if test != expected:
                mismatches.append((expected, test))

        self.assertTrue(
            len(mismatches) == 0,
            "Mismatches in line_compare:\n\n{0}".format(
                "\n".join(
                    "- expected: '{0}'\n  got:      '{1}'".format(*item)
                    for item in mismatches
                )
            )
        )

    def line_compare_minified(self, expected_list, test_list, bootstrap=False):
        """
        Compare two lists of tree view strings.

        This responsible expects the same input as :func:`line_compare`, but does some
        additional processing on the ``expected_list``.  To explain, let's take a look
        at the lines involved in the actual minified output:

        +-------+-----------------------------------------------+------------------------------------------------------------------+
        | Index | Collapsible Lists (HTML Unordered List)       | Bootstrap Version (JavaScript Function Returning JSON)           |
        +=======+===============================================+==================================================================+
        | 0     | ``<ul class="treeView" id="class-treeView">`` | ``<script type="text/javascript">``                              |
        +-------+-----------------------------------------------+------------------------------------------------------------------+
        | 1     | ``<li>``                                      | ``function getClassHierarchyTree() {``                           |
        +-------+-----------------------------------------------+------------------------------------------------------------------+
        | 2     | ``<ul class="collapsibleList">``              | ``return [``                                                     |
        +-------+-----------------------------------------------+------------------------------------------------------------------+
        | 3     | ``<<< really long >>>``                       | ``<<< really long >>>``                                          |
        +-------+-----------------------------------------------+------------------------------------------------------------------+
        | 4     | ``</ul>``                                     | ``]``                                                            |
        +-------+-----------------------------------------------+------------------------------------------------------------------+
        | 5     | ``</li><!-- only tree view element -->``      | ``}``                                                            |
        +-------+-----------------------------------------------+------------------------------------------------------------------+
        | 6     | ``</ul><!-- /treeView class-treeView -->``    | ``</script><!-- end getClassHierarchyTree() function --></div>`` |
        +-------+-----------------------------------------------+------------------------------------------------------------------+

        By convenience and design, line ``3`` is really the thing we want to test,
        because that is the meat of the tree view.  For completeness indices ``[0,3)``
        and ``[4,6]`` are also validated, but constructing line ``3`` from the provided
        ``expected_list`` (the **non**-minified ground truth) is the focus of this
        test function.

        **Parameters**
            ``expected_list`` (:class:`python:list` of :class:`python:str`)
                The expected list of strings to compare with.

            ``test_list`` (:class:`python:list` of :class:`python:str`)
                The parsed list of strings to validate.

            ``bootstrap`` (:class:`python:bool`)
                If ``False``, test is a Collapsible Lists test.  If ``True``, test is
                a Bootstrap test.
        """  # noqa: E501
        # First, compare the head / tail of the lists.
        indices            = (0, 1, 2, -1, -2, -3)
        expected_head_tail = [expected_list[idx] for idx in indices]
        test_head_tail     = [test_list[idx] for idx in indices]
        self.line_compare(expected_head_tail, test_head_tail)

        # Join the remaining elements to make a comparison.
        start    = max(indices) + 1 + int(bootstrap)  # TODO: uh. Why + int(bootstrap)?
        end      = min(indices)
        interior = "".join(expected_list[start:end])

        if bootstrap:
            # TODO: stop copy-pasting stuff from graph.py and clean this damn framework up.................
            interior = interior.replace(': ', ':').replace(",}", "}").replace(",,", ",").replace(",]", "]")

        self.assertEqual(interior, test_list[start])

    def html_ground_truth_list(self, hierarchy, key):
        """
        Ground truth data for html-based validation tests.

        **Parameters**
            ``hierarchy`` (:class:`python:str`)
                Should **only** be ``"class"`` or ``"file"``.  Indexes into
                :data:`class_hierarchy_ground_truth` and
                :data:`file_hierarchy_ground_truth` respectively.

            ``key`` (:class:`python:str`)
                The key to lookup in either :data:`class_hierarchy_ground_truth` or
                :data:`file_hierarchy_ground_truth`.  Specifically, you really only
                want to be using ``"collapsible_lists"`` or ``"bootstrap"``, since the
                raw reStructuredText version (``createTreeView=False``) can be compared
                directly.

        **Return** (:class:`python:list` of :class:`python:str`)
            The text specified by ``hierarchy[key]``, with every line split and lines
            filtered by :func:`filter_empty_lines`.
        """
        if hierarchy == "class":
            source = class_hierarchy_ground_truth
        elif hierarchy == "file":
            source = file_hierarchy_ground_truth

        raw_text = source[key]
        return self.filter_empty_lines([
            line.strip() for line in raw_text.splitlines()
        ])

    @confoverrides(exhale_args={"createTreeView": False})
    def test_no_custom_html(self):
        """
        Verify the default reStructuredText list appears as expected.
        """
        err_fmt = dedent("""\
            Expected
            ============================================================================
            {expected}

            Got
            ============================================================================
            {got}
        """)
        test_class_view, test_file_view = self.raw_hierarchies()

        class_default = class_hierarchy_ground_truth["default_rst_list"]
        self.assertTrue(
            class_default in test_class_view,
            err_fmt.format(expected=class_default, got=test_class_view))

        file_default = file_hierarchy_ground_truth["default_rst_list"]
        self.assertTrue(
            file_default in test_file_view,
            err_fmt.format(expected=file_default, got=test_file_view)
        )

    @confoverrides(exhale_args={
        "createTreeView": True,
        "minifyTreeView": False,
        "treeViewIsBootstrap": False
    })
    def test_collapsible_lists(self):
        """
        Verify the *un-minified* collapsible lists html unordered list appears as expected.
        """
        test_class_view_lines, test_file_view_lines = self.html_hierarchies()
        expected_class_view_lines = self.html_ground_truth_list("class", "collapsible_lists")
        expected_file_view_lines = self.html_ground_truth_list("file", "collapsible_lists")

        self.line_compare(expected_class_view_lines, test_class_view_lines)
        self.line_compare(expected_file_view_lines, test_file_view_lines)

    @confoverrides(exhale_args={
        "createTreeView": True,
        "minifyTreeView": True,
        "treeViewIsBootstrap": False
    })
    def test_collapsible_lists_minified(self):
        """
        Verify the *minified* collapsible lists html unordered list appears as expected.
        """
        test_class_view_lines, test_file_view_lines = self.html_hierarchies()
        expected_class_view_lines = self.html_ground_truth_list("class", "collapsible_lists")
        expected_file_view_lines = self.html_ground_truth_list("file", "collapsible_lists")

        self.line_compare_minified(expected_class_view_lines, test_class_view_lines, bootstrap=False)
        self.line_compare_minified(expected_file_view_lines, test_file_view_lines, bootstrap=False)

    @confoverrides(exhale_args={
        "createTreeView": True,
        "minifyTreeView": False,
        "treeViewIsBootstrap": True
    })
    def test_bootstrap(self):
        """
        Verify the *un-minified* bootstrap json data list appears as expected.
        """
        test_class_view_lines, test_file_view_lines = self.html_hierarchies()
        expected_class_view_lines = self.html_ground_truth_list("class", "bootstrap")
        expected_file_view_lines = self.html_ground_truth_list("file", "bootstrap")

        self.line_compare(expected_class_view_lines, test_class_view_lines)
        self.line_compare(expected_file_view_lines, test_file_view_lines)

    @confoverrides(exhale_args={
        "createTreeView": True,
        "treeViewIsBootstrap": True,
        "minifyTreeView": True
    })
    def test_bootstrap_minified(self):
        """
        Verify the *minified* bootstrap json data list appears as expected.
        """
        test_class_view_lines, test_file_view_lines = self.html_hierarchies()
        expected_class_view_lines = self.html_ground_truth_list("class", "bootstrap")
        expected_file_view_lines = self.html_ground_truth_list("file", "bootstrap")

        self.line_compare_minified(expected_class_view_lines, test_class_view_lines, bootstrap=True)
        self.line_compare_minified(expected_file_view_lines, test_file_view_lines, bootstrap=True)

package com.ciandt.hackathon.bitcoin.roulette;

import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
import org.springframework.web.servlet.config.annotation.EnableWebMvc;
import org.springframework.web.servlet.config.annotation.WebMvcConfigurerAdapter;

@Configuration
@EnableWebMvc
@ComponentScan(basePackages = "com.walmart.retargeting.gossip.server.rest")
public class RoulleteConfig extends WebMvcConfigurerAdapter {

}

import fastify, { fastify, fastify } from 'fastify'
import cors from '@fastify/cors'
import helmet from '@fastify/helmet'

const fastify = Fastify({
    logger:true
})

fastify.get('/', (request, reply) => {
    reply.send(
        {
            status:200
        }
    )
})

const start = async() =>{
    try {
        await fastify.listen({port:5000});
    } catch (err) {
        fastify.log.error(err);
        process.exit(1);
    }
}

start();